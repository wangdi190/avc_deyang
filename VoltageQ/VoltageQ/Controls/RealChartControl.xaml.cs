using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using VoltageQ.CommonFunc;
using System.Data;
using DevExpress.Xpf.Charts;
using System.Windows.Threading;
using System.Windows.Media.Animation;

namespace VoltageQ.Controls
{
    /// <summary>
    /// RealChartControl.xaml 的交互逻辑
    /// </summary>
    public partial class RealChartControl : UserControl
    {
        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        DispatcherTimer timeTimer = new DispatcherTimer();

        public RealChartControl()
        {
            InitializeComponent();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 5);
            timeTimer.Start();
        }

        private void Grid_Unloaded(object sender, RoutedEventArgs e)
        {
            timeTimer.Stop();
        }

        void timeTimer_Tick(object sender, EventArgs e)
        {
            UpdateChart();
        }

        public void UpdateChart()
        {
            for (int i = 0; i < chart.Diagram.Series.Count; i++)
            {
                var ele = chart.Diagram.Series.ElementAt(i);

                m_szSQL = GetSql(Convert.ToInt32(ele.Tag), ele.DisplayName);

                DataTable dt = odb.GetDt(m_szSQL);
                if (dt == null || dt.Rows.Count == 0)
                    return;

                ele.DataSource = dt;
            }
        }

        public void RemoveBar(string szName)
        {
            int nIndex = -1;
            for (int i = 0; i < chart.Diagram.Series.Count; i++)
            {
                if (chart.Diagram.Series.ElementAt(i).DisplayName == szName)
                {
                    nIndex = i;
                    break;
                }
            }
            if (nIndex != -1)
                chart.Diagram.Series.RemoveAt(nIndex);
        }

        public void AddBar(int type, string szName)
        {
            m_szSQL = GetSql(type, szName);

            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;

            //Bar2DAnimationBase[] pointAni =  { Bar2DSlideFromLeftAnimation }; 
            //Bar2DAnimationBase p = new Bar2DSlideFromLeftAnimation();

            BarSideBySideSeries2D bar = new BarSideBySideSeries2D();
            bar.ArgumentDataMember = "NAME";
            bar.ValueDataMember = "VALUE";
            bar.Tag = type;
            bar.DisplayName = szName;
            bar.PointAnimation = new Bar2DSlideFromLeftAnimation();
            bar.LabelsVisibility = true;
            bar.DataSource = dt;

            chart.Diagram.Series.Add(bar);
        }

        string GetSql(int type, string szName)
        {
            string szSQL = "";
            m_szTmp = string.Format("r_type={0} and r_name='{1}' and r_isreal=1", type, szName);
            //m_szTmp = string.Format("r_type={0} and r_name='{1}'", type, szName);
            //1系统，2区域，3厂站，4电压等级
            if (type == 1)//系统
            {
                szSQL = string.Format(@"select '电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select '无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select '闭锁率',R_RLOCK from avc_realsystem where {0} union 
                                    select '网损率',R_RLOSS from avc_realsystem where {0} union 
                                    select '负载率',R_RBURDEN from avc_realsystem where {0} union 
                                    select '无功备用率',R_RBACKUPQ from avc_realsystem where {0} union 
                                    select '状态估计合格率',R_RSE from avc_realsystem where {0}",
                                    m_szTmp);
            }
            else if (type == 2)//区域
            {
                szSQL = string.Format(@"select '电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select '无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select '闭锁率',R_RLOCK from avc_realsystem where {0} union 
                                    select '负载率',R_RBURDEN from avc_realsystem where {0} union 
                                    select '无功备用率',R_RBACKUPQ from avc_realsystem where {0}",
                                    m_szTmp);
            }
            else if (type == 3)//厂站
            {
                szSQL = string.Format(@"select '电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select '无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select '闭锁率',R_RLOCK from avc_realsystem where {0} union 
                                    select '负载率',R_RBURDEN from avc_realsystem where {0} union 
                                    select '无功备用率',R_RBACKUPQ from avc_realsystem where {0}",
                                    m_szTmp);
            }
            else if (type == 4)//电压等级
            {
                szSQL = string.Format(@"select '电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select '无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select '闭锁率',R_RLOCK from avc_realsystem where {0}",
                                    m_szTmp);
            }
            return szSQL;
        }


        public void Hide()
        {
            chart.Legend.Visibility = Visibility.Collapsed;
        }

        public void Show()
        {
            chart.Legend.Visibility = Visibility.Visible;
        }
    }
}

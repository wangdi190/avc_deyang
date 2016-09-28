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

namespace VoltageQ.Controls
{
    /// <summary>
    /// DayChartControl.xaml 的交互逻辑
    /// </summary>
    public partial class DayChartControl : UserControl
    {
        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        DispatcherTimer timeTimer = new DispatcherTimer();

        public DayChartControl()
        {
            InitializeComponent();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 10);
            timeTimer.Start();
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

            BarSideBySideSeries2D bar = new BarSideBySideSeries2D();
            bar.ArgumentDataMember = "NAME";
            bar.ValueDataMember = "VALUE";
            bar.DisplayName = "";
            bar.Tag = type;
            bar.DisplayName = szName;
            bar.PointAnimation = new Bar2DSlideFromRightAnimation();
            bar.DataSource = dt;

            chart.Diagram.Series.Add(bar);
        }

        string GetSql(int type, string szName)
        {
            string szSQL = "";
            m_szTmp = string.Format("where d_type={0} and d_name='{1}' and d_isday=1 and trunc(d_time)=trunc(sysdate)", type, szName);
            //m_szTmp = string.Format("where d_type={0} and d_name='{1}' and d_isday=1", type, szName);
            if (type == 1)
            {
                szSQL = string.Format(@"select '电压合格率' as name,D_VOL_RATE as value from avc_daysystem {0} union
                                        select 'AVC使用率',D_AVCUSE_RATE from avc_daysystem {0} union
                                        select '无功合格率',D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 2)
            {
                szSQL = string.Format(@"select '电压合格率' as name,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 3)
            {
                szSQL = string.Format(@"select '电压合格率' as name,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 4)
            {
                szSQL = string.Format(@"select '电压合格率' as name,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',D_LOCK_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else
                szSQL = "";
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

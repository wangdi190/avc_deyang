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
using VoltageQ.ViewModels;
using VoltageQ.CommonFunc;
using System.Data;
using DevExpress.Xpf.Charts;
using System.Windows.Threading;

namespace VoltageQ.Controls
{
    /// <summary>
    /// DayCurveControl.xaml 的交互逻辑
    /// </summary>
    public partial class DayCurveControl : UserControl
    {

        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        DispatcherTimer timeTimer = new DispatcherTimer();

        public DayCurveControl()
        {
            InitializeComponent();
            //this.DataContext = new DayCurveControlModel();
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
            data = odb.GetDt(m_szSQL);

            if (data == null || data.Rows.Count == 0)
                return;

            chart.Diagram.SeriesDataMember = "name";
            chart.Diagram.SeriesTemplate.ArgumentDataMember = "argument";
            chart.Diagram.SeriesTemplate.ValueDataMember = "value";
            chart.DataSource = data;
        }

        public void AddCurve(int type, string szName)
        {
            foreach (RadioButton rad in rightStack.Children.OfType<RadioButton>())
            {
                rad.IsChecked = false;
            }

            RadioButton radio = new RadioButton();
            radio.Content = szName;
            radio.Tag = type;
            radio.GroupName = "wd";
            
            radio.Checked += new RoutedEventHandler(radio_Checked);
            radio.IsChecked = true;

            rightStack.Children.Add(radio);
        }

        public void DeleteCurve(int type, string szName)
        {
            bool bCheck=false;
            foreach (RadioButton radio in rightStack.Children.OfType<RadioButton>())
            {
                if (radio.Content == szName)
                {
                    if (radio.IsChecked == true)
                        bCheck = true;
                    rightStack.Children.Remove(radio);
                    break;
                }
            }

            if (bCheck == true)
            {
                foreach (RadioButton radio in rightStack.Children.OfType<RadioButton>())
                {
                    radio.IsChecked = true;
                    break;
                }
            }
        }


        void radio_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton radio = sender as RadioButton;

            chart.DataSource = null;

            m_szSQL = GetSql(Convert.ToInt32(radio.Tag), radio.Content.ToString());
            data = odb.GetDt(m_szSQL) ;

            if (data == null || data.Rows.Count == 0)
                return;

            chart.Diagram.SeriesDataMember = "name";
            chart.Diagram.SeriesTemplate.ArgumentDataMember = "argument";
            chart.Diagram.SeriesTemplate.ValueDataMember = "value";
            chart.DataSource = data;
        }

        string GetSql(int type, string szName)
        {
            string szSQL = "";
            m_szTmp = string.Format("where d_type={0} and trunc(d_time)=trunc(sysdate) and d_name='{1}'", type, szName);
            //m_szTmp = string.Format("where d_type={0} and d_name='{1}'", type, szName);
            if (type == 1)
            {
                szSQL = string.Format(@"select '电压合格率' as name,d_time as argument,D_VOL_RATE as value from avc_daysystem {0} union
                                        select 'AVC使用率',d_time as argument,D_AVCUSE_RATE from avc_daysystem {0} union
                                        select '无功合格率',d_time as argument,D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',d_time as argument,D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',d_time as argument,D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',d_time as argument,D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',d_time as argument,D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',d_time as argument,D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 2)
            {
                szSQL = string.Format(@"select '电压合格率' as name,d_time as argument,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',d_time as argument,D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',d_time as argument,D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',d_time as argument,D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',d_time as argument,D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',d_time as argument,D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',d_time as argument,D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 3)
            {
                szSQL = string.Format(@"select '电压合格率' as name,d_time as argument,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',d_time as argument,D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',d_time as argument,D_LOCK_RATE from avc_daysystem {0} union
                                        select '控制使用率',d_time as argument,D_AVCCTRLUSE_RATE from avc_daysystem {0} union
                                        select '控制成功率',d_time as argument,D_AVCACTSUCC_RATE from avc_daysystem {0} union
                                        select 'AVC响应率',d_time as argument,D_AVCRESP_RATE from avc_daysystem {0} union
                                        select 'AVC控制率',d_time as argument,D_AVCCAPAB_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else if (type == 4)
            {
                szSQL = string.Format(@"select '电压合格率' as name,d_time as argument,D_VOL_RATE as value from avc_daysystem {0} union
                                        select '无功合格率',d_time as argument,D_COS_RATE from avc_daysystem {0} union
                                        select '设备闭锁率',d_time as argument,D_LOCK_RATE from avc_daysystem {0}",
                                        m_szTmp);
            }
            else
                szSQL = "";
            return szSQL;
        }

        private void rightStack_MouseEnter(object sender, MouseEventArgs e)
        {
            rightStack.Opacity = 1;
        }

        private void rightStack_MouseLeave(object sender, MouseEventArgs e)
        {
            rightStack.Opacity = 0.4;
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

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
using System.Data;
using VoltageQ.CommonFunc;
using System.Windows.Threading;

namespace VoltageQ.Views
{
    public partial class StationView : UserControl
    {
       // public string m_szStationID = "";
        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        DispatcherTimer timeTimer = null;//new DispatcherTimer();

        public bool Hide
        {
            set
            {
                if (value == false)
                {
                    this.Visibility = Visibility.Visible;
                    Update();
                    if (timeTimer != null)
                        timeTimer.Start();
                }
                else
                {
                    this.Visibility = Visibility.Collapsed;
                    if (timeTimer != null)
                        timeTimer.Stop();
                }
            }
        }

        public StationView()
        {
            InitializeComponent();
            timeTimer = new DispatcherTimer();
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 30);
            timeTimer.Start();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            if (Math.Abs(navbar.ActualHeight) > 1)
            {
                lv_bus.Height = navbar.ActualHeight - 90;
                lv_tfm.Height = navbar.ActualHeight - 90;
                lv_shunt.Height = navbar.ActualHeight - 90;
            }
        }

        private void Grid_Unloaded(object sender, RoutedEventArgs e)
        {
            if (timeTimer != null)
                timeTimer.Stop();
            GC.Collect();
        }

        void timeTimer_Tick(object sender, EventArgs e)
        {
            Update();
        }

        public void Update()
        {
            UpdateChart();
            Station_Curve.Update(GlobalInfo.selStationID);
            UpdateNavBar();
            UpdateControlView();
            
        }

        void UpdateControlView()
        {
            m_szSQL = string.Format("select isstm 时间,cause_info 控制原因,result_info 措施,cmd_info 命令描述,rslttype 处理状态 from avc_ctrlcmd where stationid={0} and cmdtype='控制' and trunc(isstm)=trunc(sysdate)", GlobalInfo.selStationID);
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null&& dt.Rows.Count>0)
                return;

            controlView.ItemsSource = dt.DefaultView;
        }

        void UpdateChart()
        {
//            m_szTmp = string.Format("d_isday=1 and d_type=3 and d_id={0}", m_szStationID);
//            m_szSQL = string.Format(@"select D_TIME,'电压合格率' as name,D_VOL_RATE as value from avc_daysystem where {0} union
//select D_TIME,'无功合格率',D_COS_RATE from avc_daysystem where {0} union
//select D_TIME,'AVC控制率',D_AVCCAPAB_RATE from avc_daysystem where {0} union
//select D_TIME,'AVC响应率',D_AVCRESP_RATE from avc_daysystem where {0} union
//select D_TIME,'AVC控制成功率',D_AVCACTSUCC_RATE from avc_daysystem where {0} union
//select D_TIME,'AVC控制使用率',D_AVCCTRLUSE_RATE from avc_daysystem where {0} union
//select D_TIME,'设备闭锁率',D_LOCK_RATE from avc_daysystem where {0}", m_szTmp);

            m_szTmp = string.Format("r_type=3 and r_id={0} and r_isreal=1", GlobalInfo.selStationID);
            m_szSQL = string.Format(@"select 1,r_time,R_name,'电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select 2,r_time,R_name,'无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select 4,r_time,R_name,'可用率',R_RLOCK from avc_realsystem where {0} union 
                                    select 3,r_time,R_name,'负载率',R_RBURDEN from avc_realsystem where {0} union 
                                    select 5,r_time,R_name,'无功备用率',R_RBACKUPQ from avc_realsystem where {0}",
                                    m_szTmp);

            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;
           
                //if (dt.Rows.Count > 0)
                    //CrosshairOpt.CrosshairLabelPattern = dt.Rows[0]["R_TIME"].ToString() + "\n{A}:{V}";
                    //CrosshairOpt.GroupHeaderPattern = Convert.ToString((dt.Rows[0])["R_TIME"]) + "\n{A}";

                //chart.Diagram.SeriesDataMember = "R_NAME";
                //chart.Diagram.SeriesTemplate.ArgumentDataMember = "NAME";
                //chart.Diagram.SeriesTemplate.ValueDataMember = "VALUE";
                //chart.DataSource = dt.DefaultView;

            chart_bar.ArgumentDataMember = "NAME";
            chart_bar.ValueDataMember = "VALUE";
            chart_bar.DataSource = dt.DefaultView;
        }

        void UpdateNavBar()
        {
            m_szSQL = string.Format("select M_TIME,M_NAME,M_VOL,M_VMIN,M_VMAX from avc_bus where m_station={0}", GlobalInfo.selStationID);
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_bus.ItemsSource = dt.DefaultView;

            m_szSQL = string.Format("select M_time 时间,m_name 名称,m_s 变压器容量,m_p 当前有功, m_q 当前无功,m_cos 当前功率, m_tap 当前档位,m_cosmin 功率下限,m_cosmax 功率上限  from avc_trans where m_station={0} order by 当前功率 desc", GlobalInfo.selStationID);
            dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_tfm.ItemsSource = dt.DefaultView;

            m_szSQL = string.Format("select M_TIME,M_NAME,M_S,M_Q from avc_shunt where m_station={0}", GlobalInfo.selStationID);
            dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_shunt.ItemsSource = dt.DefaultView;
        }

        private void UserControl_IsVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            if (this.Visibility == Visibility.Collapsed)
                timeTimer.Stop();
            else if (this.Visibility == Visibility.Visible)
                timeTimer.Start();
            else if (this.Visibility == Visibility.Hidden)
                timeTimer.Stop();
        }

        
    }
}

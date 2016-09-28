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
using System.Windows.Threading;
using VoltageQ.CommonFunc;
using DevExpress.Xpf.Charts;
using System.Threading;
using DevExpress.Xpf.Grid;
using DevExpress.Xpf.Editors.Settings;

namespace VoltageQ.Views
{
    /// <summary>
    /// ZoneView.xaml 的交互逻辑
    /// </summary>
    public partial class ZoneView : UserControl
    {
        //public string m_szZoneID = "";
        string m_szSQL, m_szTmp, m_szCurChoose = "电压";
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

        public ZoneView()
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
                lv_voltage.Height = navbar.ActualHeight - 115;
                lv_reactive.Height = navbar.ActualHeight - 115;
                lv_atresia.Height = navbar.ActualHeight - 115;
                lv_load.Height = navbar.ActualHeight - 115;
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
            UpdateRadar();
            ZoneChart.UpdateCharts(GlobalInfo.selStationID);
            daycurve.Update(GlobalInfo.selStationID);
            UpdateNavBar();
        }

        private void UpdateRadar()
        {
            //chart.Diagram.Series.Clear();
            dyhgl_Rate.Text = "0%";
            wghgl_Rate.Text = "0%";
            bsl_Rate.Text = "0%";
            fzl_Rate.Text = "0%";
            wgbyl_Rate.Text = "0%";
            m_szTmp = string.Format("r_type=2 and r_id={0} and r_isreal=1", GlobalInfo.selStationID);
            m_szSQL = string.Format(@"select 1,r_time,'电压合格率' as name,r_rvol as value from avc_realsystem where {0} union
                                    select 2,r_time,'无功合格率',R_RCOS from avc_realsystem where {0} union
                                    select 4,r_time,'可用率',R_RLOCK from avc_realsystem where {0} union 
                                    select 3,r_time,'负载率',R_RBURDEN from avc_realsystem where {0} union 
                                    select 5,r_time,'无功备用率',R_RBACKUPQ from avc_realsystem where {0}",
                                    m_szTmp);
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt != null)
            {
                if (dt.Rows.Count > 0)
                    radar.ToolTipPointPattern = dt.Rows[0]["R_TIME"].ToString() + "\n{A}:{V}";

                radar.DataSource = dt;

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    switch (dt.Rows[i]["NAME"].ToString())
                    {
                        case "电压合格率":
                        dyhgl_Rate.Text = string.Format("{0:F}%", dt.Rows[i]["VALUE"]);
                    	break;
                        case "无功合格率":
                        wghgl_Rate.Text = string.Format("{0:F}%", dt.Rows[i]["VALUE"]);
                        break;
                        case "可用率":
                        bsl_Rate.Text = string.Format("{0:F}%", dt.Rows[i]["VALUE"]);
                        break;
                        case "负载率":
                        fzl_Rate.Text = string.Format("{0:F}%", dt.Rows[i]["VALUE"]);
                        break;
                        case "无功备用率":
                        wgbyl_Rate.Text = string.Format("{0:F}%", dt.Rows[i]["VALUE"]);
                        break;
                    }
                    //TextBlock lab = (TextBlock)panel.Children[i];
                    //((Run)lab.Inlines.ElementAt(0)).Text = " " + dt.Rows[i]["NAME"].ToString() + ":";
                    //((Run)lab.Inlines.ElementAt(2)).Text = string.Format("{0:F}", dt.Rows[i]["VALUE"]);
                }
            }
        }

        private void UpdateNavBar()
        {
            //if (Math.Abs(navbar.ActualHeight) > 1)
            //{
            //    lv_voltage.Height = navbar.ActualHeight - 115;
            //    lv_reactive.Height = navbar.ActualHeight - 115;
            //    lv_atresia.Height = navbar.ActualHeight - 115;
            //    lv_load.Height = navbar.ActualHeight - 115;
            //}

            m_szSQL = string.Format("select M_time 时间,m_name 名称,m_vol 电压,m_vmax 电压上限,m_vmin 电压下限 from avc_bus where m_outsta=1 and m_zone={0} order by 名称", GlobalInfo.selStationID);
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_voltage.ItemsSource = dt.DefaultView;

            m_szSQL = string.Format("select M_time 时间,m_name 名称,m_s 变压器容量,m_p 当前有功, m_q 当前无功,m_cos 当前功率, m_tap 当前档位,m_cosmin 功率下限,m_cosmax 功率上限  from avc_trans where m_outsta=1 and m_zone={0} order by 当前功率 desc", GlobalInfo.selStationID);
            dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_reactive.ItemsSource = dt.DefaultView;

            m_szSQL = string.Format(@"select M_time 时间,'电容' 设备类型,m_name 名称 from avc_shunt where m_locksta=1 and m_zone={0} union
select M_time 时间,'变压器' 设备类型,m_name 名称 from avc_trans where m_locksta=1 and m_zone={0} union
select M_time 时间,'母线' 设备类型,m_name 名称 from avc_bus where m_locksta=1 and m_zone={0}", GlobalInfo.selStationID);
            dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_atresia.ItemsSource = dt.DefaultView;

            m_szSQL = string.Format("select r_time 时间,r_name 名称,R_SHUNTQ 电容投入Q,R_SHUNTALLQ 总电容容量Q,R_SYSLOADS 系统负载S,R_SYSTEMS 系统容量S  from avc_realloss where r_isreal=1 and r_type=2 and r_id={0}", GlobalInfo.selStationID);
            dt = odb.GetDt(m_szSQL);
            if (dt != null)
                lv_load.ItemsSource = dt.DefaultView;
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

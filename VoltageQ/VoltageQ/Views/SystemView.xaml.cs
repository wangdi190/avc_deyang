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
using DevExpress.Xpf.Charts;
using System.Data;
using VoltageQ.CommonFunc;
using System.Windows.Threading;
using DevExpress.Xpf.Grid;
using DevExpress.XtraEditors.DXErrorProvider;
using DevExpress.Xpf.Editors.Settings;

namespace VoltageQ.Views
{
    /// <summary>
    /// SystemView.xaml 的交互逻辑
    /// </summary>
    public partial class SystemView : UserControl
    {
        string m_szSQL, m_szTmp, m_szCurChoose="电压";
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
                    if(timeTimer != null)
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


        public SystemView()
        {
            InitializeComponent();

            timeTimer = new DispatcherTimer(); ;
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 30);
            timeTimer.Start();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
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
            daycurve.Update("0");
            UpdateChart();
        }

        //public string chartTime = null;
        //public string ChartTime { get { return chartTime; } set { chartTime = value; } }

        public void UpdateChart()
        {
            m_szSQL = @"select * from 
(select 1 as orderby,r_time,r_type,r_name,'电压合格率' as name,R_RVOL as value from AVC_Realsystem where r_type in (1,2) and r_isreal=1 union
select 2,r_time,r_type,r_name,'无功合格率',R_RCOS from AVC_Realsystem where r_type in (1,2) and r_isreal=1 union
select 5,r_time,r_type,r_name,'可用率',R_RLOCK from AVC_Realsystem where r_type in (1,2) and r_isreal=1 union
select 3,r_time,r_type,r_name,'负载率',R_RBURDEN from AVC_Realsystem where r_type in (1,2) and r_isreal=1 union
select 4,r_time,r_type,r_name,'无功备用率',R_RBACKUPQ from AVC_Realsystem where r_type in (1,2) and r_isreal=1 union
select 6,r_time,r_type,r_name,'网损率',R_RLOSS from AVC_Realsystem where r_type in (1,2) and r_isreal=1)order by r_type,orderby";
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;

            if (dt.Rows.Count > 0)
                CrosshairOpt.GroupHeaderPattern = Convert.ToString((dt.Rows[0])["R_TIME"]) + "\n{A}";
            chart.Diagram.SeriesDataMember = "NAME";
            chart.Diagram.SeriesTemplate.ArgumentDataMember = "R_NAME";
            chart.Diagram.SeriesTemplate.ValueDataMember = "VALUE";
            chart.DataSource = dt.DefaultView;

            UpdateDetail(m_szCurChoose);
            UpdateText();
        }

        public void UpdateText()
        {
            m_szSQL = "select R_AVCSTA,R_AVCCTRLSTA,R_ISLAND from avc_realsystem where r_isreal=1 and r_type=1";
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null)
                return;

            foreach (DataRow dr in dt.Rows)
            {
                int a = info.Inlines.Count;
                ((Run)info.Inlines.ElementAt(2)).Text = dr["R_AVCSTA"].ToString();
                ((Run)info.Inlines.ElementAt(6)).Text = dr["R_AVCCTRLSTA"].ToString();
                ((Run)info.Inlines.ElementAt(10)).Text = dr["R_ISLAND"].ToString();
                
                //info.Text = string.Format("AVC运行状态:{0} AVC控制状态:{1} 电气岛数:{2}",
                //    dr["R_AVCSTA"], dr["R_AVCCTRLSTA"], dr["R_ISLAND"]);
            }
        }

        public void UpdateDetail(string name)
        {
            m_szSQL = "";
            if (name == "电压")
                m_szSQL = "select a.M_time 时间,b.m_name||'.'||a.m_name 名称,a.m_vol 电压,a.m_vmax 电压上限,a.m_vmin 电压下限 from avc_bus a, avc_syszone b where a.m_outsta=1 and a.m_zone=b.m_id order by m_vl desc";
            else if (name == "无功")
                m_szSQL = "select a.M_time 时间,b.m_name||'.'||a.m_name 名称,a.m_s 变压器容量,a.m_p 当前有功, a.m_q 当前无功,a.m_cos 当前功率, a.m_tap 当前档位,a.m_cosmin 功率下限,a.m_cosmax 功率上限  from avc_trans a,avc_syszone b where m_outsta=1 and a.m_zone=b.m_id order by m_cos";
            else if (name == "控制")
                m_szSQL = @"select a.M_time 时间,'电容' 设备类型,b.m_name||'.'||a.m_name 名称 from avc_shunt a,avc_syszone b where trunc(a.m_time)=trunc(sysdate) and a.m_ctrlsta=1 and a.m_zone=b.m_id
union select a.M_time 时间,'变压器' 设备类型,b.m_name||'.'||a.m_name 名称 from avc_trans a,avc_syszone b where trunc(a.m_time)=trunc(sysdate) and a.m_ctrlsta=1 and a.m_zone=b.m_id";
            else if (name == "负载")
                m_szSQL = "select r_time 时间,r_name 名称,R_SHUNTQ 电容投入Q,R_SHUNTALLQ 总电容容量Q,R_SYSLOADS 系统负载S,R_SYSTEMS 系统容量S  from avc_realloss where r_isreal=1 and r_type in (1,2)";
            else if (name == "闭锁")
                m_szSQL = @"select a.M_time 时间,'电容' 设备类型,b.m_name||'.'||a.m_name 名称 from avc_shunt a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id union
select a.M_time 时间,'变压器' 设备类型,b.m_name||'.'||a.m_name 名称 from avc_trans a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id union
select a.M_time 时间,'母线' 设备类型,b.m_name||'.'||a.m_name 名称 from avc_bus a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id";
            else if (name == "网损")
                m_szSQL = "select r_time 时间,r_name 名称,R_GENP 电机总P,R_GENQ 电机总Q,R_LOADP 负荷总P,R_LOADQ 负荷总Q,R_LINEP 线路网损P,R_LINEQ 线路网损Q,R_TRANSP 变压器网损P,R_TRANSQ 变压器网损Q,R_SHUNTQ 电容投入Q  from avc_realloss where r_isreal=1 and r_type in (1,2)";
            
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null)
                return;

            if (grid_system.Tag.ToString() == "0")
            {
                for (int i = 0; i < dt.Columns.Count; i++)
                {
                    GridColumn column = new GridColumn();
                    column.FieldName = dt.Columns[i].ColumnName;
                    if (column.FieldName == "时间")
                    {
                        column.EditSettings = new DateEditSettings() { DisplayFormat = "yyyy-MM-dd HH:mm:ss" };
                        column.Width = 150;
                    }
                    else if (column.FieldName == "名称")
                    {
                        column.Width = 200;
                    }
                    grid_system.Columns.Add(column);
                }
                grid_system.Tag = "1";
            }

            grid_system.ItemsSource = dt.DefaultView;
            m_szCurChoose = name;


            m_szSQL = "select count(*) as num from avc_bus a, avc_syszone b where a.m_outsta=1 and a.m_zone=b.m_id";
            dt = odb.GetDt(m_szSQL);
            if (dt != null && dt.Rows.Count > 0)
                dy_num.Text = dt.Rows[0]["NUM"].ToString();

            m_szSQL = "select count(*) as num  from avc_trans a,avc_syszone b where m_outsta=1 and a.m_zone=b.m_id";
            dt = odb.GetDt(m_szSQL);
            if (dt != null && dt.Rows.Count > 0)
                wg_num.Text = dt.Rows[0]["NUM"].ToString();

            m_szSQL = @"select e.num1+f.num2 as num from 
(select count(*) as num1 from avc_shunt a,avc_syszone b where trunc(a.m_time)=trunc(sysdate) and a.m_ctrlsta=1 and a.m_zone=b.m_id)e,
(select count(*) as num2 from avc_trans a,avc_syszone b where trunc(a.m_time)=trunc(sysdate) and a.m_ctrlsta=1 and a.m_zone=b.m_id)f";
            dt = odb.GetDt(m_szSQL);
            if (dt != null && dt.Rows.Count > 0)
                kz_num.Text = dt.Rows[0]["NUM"].ToString();

            m_szSQL = @"select e.num1+f.num2+g.num3 as num from 
(select count(*) as num1 from avc_shunt a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id) e,
(select count(*) as num2 from avc_trans a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id) f,
(select count(*) as num3 from avc_bus a,avc_syszone b where a.m_locksta=1 and a.m_zone=b.m_id)g";
            dt = odb.GetDt(m_szSQL);
            if (dt != null && dt.Rows.Count > 0)
                bs_num.Text = dt.Rows[0]["NUM"].ToString();
        }

        private void Border_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            Border btn = sender as Border;
            if (m_szCurChoose == btn.Tag.ToString())
                return;

            for (int i = 0; i < grid_system.Columns.Count; i++ )
            {
                grid_system.ClearColumnFilter(grid_system.Columns[i]);
            }

            grid_system.Columns.Clear();
            m_szCurChoose = btn.Tag.ToString();
            grid_system.Tag = "0";
            UpdateDetail(m_szCurChoose);
        }

        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    Button btn = sender as Button;
        //    if (m_szCurChoose == btn.Content.ToString())
        //        return;

        //    for (int i = 0; i < grid_system.Columns.Count; i++ )
        //    {
        //        grid_system.ClearColumnFilter(grid_system.Columns[i]);
        //    }

        //    grid_system.Columns.Clear();

        //    m_szCurChoose = btn.Content.ToString();
        //    grid_system.Tag = "0";
        //    UpdateDetail(m_szCurChoose);
        //}

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

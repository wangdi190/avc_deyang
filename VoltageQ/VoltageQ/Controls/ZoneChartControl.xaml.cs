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

namespace VoltageQ.Controls
{
    /// <summary>
    /// ZoneChartControl.xaml 的交互逻辑
    /// </summary>
    public partial class ZoneChartControl : UserControl
    {
        public string m_szZoneID = "";
        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
       // DispatcherTimer timeTimer = new DispatcherTimer();

        public ZoneChartControl()
        {
            InitializeComponent();
        }

        public void UpdateCharts(string nZoneID)
        {
            m_szZoneID = nZoneID;

            m_szSQL = string.Format(@"select b.m_name as STATIONNAME,a.* from 
(select r_time,r_id as stationid,'电压合格率'as name_dy,r_rvol as value_dy,'无功合格率' as name_wghgl,R_RCOS as value_wghgl,
 '网损率'as name_ws,R_RLOSS as value_ws,'负载率' as name_fz,R_RBURDEN as value_fz,
 '可用率'as name_bs,R_RLOCK as value_bs,'无功备用率' as name_wgby,R_RBACKUPQ as value_wgby,r_sysloads
from AVC_Realsystem where r_type=3 and r_isreal=1)a,
(select * from avc_station where m_zone={0})b
where a.stationid=b.m_id order by r_sysloads desc", m_szZoneID);

            DataTable dt = odb.GetDt(m_szSQL);
            if (dt != null)
            {
                if (dt.Rows.Count > 0)
                    CrosshairOpt.GroupHeaderPattern = Convert.ToString((dt.Rows[0])["R_TIME"]) + "\n{A}";

                chart_dy.ArgumentDataMember = "STATIONNAME";
                chart_dy.ValueDataMember = "VALUE_DY";
                chart_dy.DataSource = dt.DefaultView;

                chart_wghgl.ArgumentDataMember = "STATIONNAME";
                chart_wghgl.ValueDataMember = "VALUE_WGHGL";
                chart_wghgl.DataSource = dt.DefaultView;

                chart_ws.ArgumentDataMember = "STATIONNAME";
                chart_ws.ValueDataMember = "VALUE_WS";
                chart_ws.DataSource = dt.DefaultView;

                chart_fz.ArgumentDataMember = "STATIONNAME";
                chart_fz.ValueDataMember = "VALUE_FZ";
                chart_fz.DataSource = dt.DefaultView;

                chart_bs.ArgumentDataMember = "STATIONNAME";
                chart_bs.ValueDataMember = "VALUE_BS";
                chart_bs.DataSource = dt.DefaultView;

                chart_wgbyl.ArgumentDataMember = "STATIONNAME";
                chart_wgbyl.ValueDataMember = "VALUE_WGBY";
                chart_wgbyl.DataSource = dt.DefaultView;
            }
        }
    }
}

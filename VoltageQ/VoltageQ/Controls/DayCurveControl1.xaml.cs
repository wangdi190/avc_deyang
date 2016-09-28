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
using DevExpress.Xpf.Charts;

namespace VoltageQ.Controls
{
    /// <summary>
    /// DayCurveControl1.xaml 的交互逻辑
    /// </summary>
    public partial class DayCurveControl1 : UserControl
    {
   //     public string m_szZoneID = "";
        string m_szSQL, m_szTmp;
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        //DispatcherTimer timeTimer = new DispatcherTimer();

        public DayCurveControl1()
        {
            InitializeComponent();
        }

        public void Update(string szStationID)
        {
            chart_dyhgl.DataSource = null;
            chart_wghgl.DataSource = null;
            chart_bsl.DataSource = null;
            chart_wgbyl.DataSource = null;
            chart_fzl.DataSource = null;
            m_szSQL = string.Format("select R_TIME,R_RVOL,R_RCOS,R_RLOCK,R_RBACKUPQ,R_RBURDEN from avc_realsystem where r_type=3 and r_id={0} and trunc(r_time)=trunc(sysdate)", szStationID);
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt != null && dt.Rows.Count>0)
            {
                //CrosshairOpt.GroupHeaderPattern = dt.Rows[0]["R_TIME"].ToString();

                chart_dyhgl.ArgumentDataMember = "R_TIME";
                chart_dyhgl.ValueDataMember = "R_RVOL";
                chart_dyhgl.DataSource = dt.DefaultView;

                chart_wghgl.ArgumentDataMember = "R_TIME";
                chart_wghgl.ValueDataMember = "R_RCOS";
                chart_wghgl.DataSource = dt.DefaultView;

                chart_bsl.ArgumentDataMember = "R_TIME";
                chart_bsl.ValueDataMember = "R_RLOCK";
                chart_bsl.DataSource = dt.DefaultView;

                chart_wgbyl.ArgumentDataMember = "R_TIME";
                chart_wgbyl.ValueDataMember = "R_RBACKUPQ";
                chart_wgbyl.DataSource = dt.DefaultView;

                chart_fzl.ArgumentDataMember = "R_TIME";
                chart_fzl.ValueDataMember = "R_RBURDEN";
                chart_fzl.DataSource = dt.DefaultView;
            }

            //m_szSQL = string.Format("select stationid,isstm, 8 as value,result_info from avc_ctrlcmd where stationid={0} and trunc(isstm)=trunc(sysdate) and cmdtype='控制'", szStationID);

            //chart_sj.DataSource = null;
            chart_sj.Points.Clear();
            m_szSQL = string.Format("select isstm, 8 as value,listagg(cmd_info,'\n') within group(order by isstm) as cmd_info  from avc_ctrlcmd where stationid={0} and trunc(isstm)=trunc(sysdate) and cmdtype='控制' group by isstm", szStationID);
            DataTable dt1 = odb.GetDt(m_szSQL);
            if (dt1 != null && dt1.Rows.Count>0)
            {

                for (int i = 0; i < dt1.Rows.Count; i++)
                {
                    SeriesPoint point = new SeriesPoint(dt1.Rows[i]["isstm"].ToString(), Convert.ToDouble(dt1.Rows[i]["VALUE"]));
                    point.Tag = dt1.Rows[i]["cmd_info"];
                    chart_sj.Points.Add(point);
                }
                  
                //chart_sj.ArgumentDataMember = "isstm";
                //chart_sj.ValueDataMember = "VALUE";
                //chart_sj.DataSource = dt1.DefaultView;
            }
            
        }

        private void chart_CustomDrawCrosshair(object sender, CustomDrawCrosshairEventArgs e)
        {
            foreach (CrosshairElement ele in e.CrosshairElements)
            {
                if (ele.Series.DisplayName == "事件")
                    ele.LabelElement.Text = ele.Series.DisplayName + ":"+ele.SeriesPoint.ActualArgument+"\n"+ele.SeriesPoint.Tag;
            }
        }

        //private void chart_CustomDrawSeriesPoint(object sender, CustomDrawSeriesPointEventArgs e)
        //{
        //    e.LabelText = e.SeriesPoint.Tag.ToString();
        //}
    }
}

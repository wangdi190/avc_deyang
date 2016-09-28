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
    /// DayCurve.xaml 的交互逻辑
    /// </summary>
    public partial class DayCurve : UserControl
    {
        string m_szSQL;
        OracleDataBase odb = new OracleDataBase();

        public DayCurve()
        {
            InitializeComponent();
            dtPicker.SelectedDate = DateTime.Today;
        }

        public void Update(string id)
        {
            tmRange.MinValue = dtPicker.SelectedDate;
            tmRange.MaxValue = dtPicker.SelectedDate.Value.AddDays(1);

            chart.DataSource = null;
            m_szSQL = string.Format("select r_time,R_RVOL 电压合格率,R_RCOS 无功合格率,R_RLOCK 可用率,R_RBURDEN 负载率,R_RBACKUPQ 无功备用率,R_RLOSS 网损率  from AVC_Realsystem where r_id={0} and r_ishis=1 and to_char(r_time,'yyyy-mm-dd')='{1}'", id, dtPicker.SelectedDate.Value.ToString("yyyy-MM-dd"));

            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;
            chart.DataSource = dt.DefaultView;


            chart_sj.Points.Clear();
            m_szSQL = string.Format("select isstm, 8 as value,listagg(cmd_info,'\n') within group(order by isstm) as cmd_info  from avc_ctrlcmd where syszone={0} and to_char(isstm,'yyyy-mm-dd')='{1}' and cmdtype='控制' group by isstm", id, dtPicker.SelectedDate.Value.ToString("yyyy-MM-dd"));
            DataTable dt1 = odb.GetDt(m_szSQL);
            if (dt1 != null && dt1.Rows.Count > 0)
            {

                for (int i = 0; i < dt1.Rows.Count; i++)
                {
                    SeriesPoint point = new SeriesPoint(dt1.Rows[i]["isstm"].ToString(), Convert.ToDouble(dt1.Rows[i]["VALUE"]));
                    point.Tag = dt1.Rows[i]["cmd_info"];
                    chart_sj.Points.Add(point);
                }
            }

        }

        private void dtPicker_SelectedDateChanged(object sender, SelectionChangedEventArgs e)
        {
            Update(GlobalInfo.selStationID);
        }

        private void chart_CustomDrawCrosshair(object sender, DevExpress.Xpf.Charts.CustomDrawCrosshairEventArgs e)
        {
            foreach (CrosshairElement ele in e.CrosshairElements)
            {
                if (ele.Series.DisplayName == "事件")
                    ele.LabelElement.Text = ele.Series.DisplayName + ":" + ele.SeriesPoint.ActualArgument + "\n" + ele.SeriesPoint.Tag;
            }
        }
    }
}

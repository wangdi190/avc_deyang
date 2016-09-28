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

namespace VoltageQ.Views
{
    /// <summary>
    /// HisZoneView.xaml 的交互逻辑
    /// </summary>
    public partial class HisZoneView : UserControl
    {
        string m_szSQL;
        OracleDataBase odb = new OracleDataBase();

        public bool Hide
        {
            set
            {
                if (value == false)
                {
                    this.Visibility = Visibility.Visible;
                    Update();
                }
                else
                {
                    this.Visibility = Visibility.Collapsed;
                }
            }
        }

        public HisZoneView()
        {
            InitializeComponent();
        }

        void Update()
        {
            lineTimeRange.MaxValue = GlobalInfo.hisDt.AddDays(1);
            lineTimeRange.MinValue = GlobalInfo.hisDt;

            lineChart.DataSource = null;
            listView.ItemsSource = null;
            radar.Points.Clear();


            m_szSQL = string.Format(@"select d_time 时间,D_AVCUSE_RATE AVC使用率,D_VOL_RATE 电压合格率,D_COS_RATE 无功合格率,D_LOCK_RATE 设备可用率,D_AVCCTRLUSE_RATE AVC应用率,
D_AVCACTSUCC_RATE AVC控制成功率,D_AVCRESP_RATE AVC响应率,D_AVCCAPAB_RATE AVC控制率
from avc_daysystem where d_id={0} and to_char(d_time,'yyyy-mm-dd')='{1}' order by d_time desc", GlobalInfo.selStationID, GlobalInfo.hisDt.ToString("yyyy-MM-dd"));
            DataTable dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;

            radar.ToolTipPointPattern = dt.Rows[0]["时间"].ToString() + "\n{A}:{V}";
            radar.Points.Add(new SeriesPoint("AVC使用率", Convert.ToDouble(dt.Rows[0]["AVC使用率"])));
            radar.Points.Add(new SeriesPoint("电压合格率", Convert.ToDouble(dt.Rows[0]["电压合格率"])));
            radar.Points.Add(new SeriesPoint("无功合格率", Convert.ToDouble(dt.Rows[0]["无功合格率"])));
            radar.Points.Add(new SeriesPoint("设备可用率", Convert.ToDouble(dt.Rows[0]["设备可用率"])));
            radar.Points.Add(new SeriesPoint("AVC应用率", Convert.ToDouble(dt.Rows[0]["AVC应用率"])));
            radar.Points.Add(new SeriesPoint("AVC控制成功率", Convert.ToDouble(dt.Rows[0]["AVC控制成功率"])));
            radar.Points.Add(new SeriesPoint("AVC响应率", Convert.ToDouble(dt.Rows[0]["AVC响应率"])));
            radar.Points.Add(new SeriesPoint("AVC控制率", Convert.ToDouble(dt.Rows[0]["AVC控制率"])));

            lineChart.DataSource = dt.DefaultView;


//            m_szSQL = string.Format(@"select D_AVCRUNTIME 运行时间,D_AVCOUTTIME AVC退出运行时间,D_AVCOPENTIME AVC控制退出时间,
//D_VOLRUNTIME 电压运行时长,D_VOLOUTTIME 电压越限时长,D_COSRUNTIME 无功运行时长,D_COSOUTTIME 无功越限时长,
//D_LOSSDEC AVC日降损量,D_DEVRUNTIME 系统设备运行时长,D_LOCKTIME 设备闭锁时长,D_ALLACT_NUM 系统动作数,
//D_AVCCTRL_NUM AVC控制数,D_AVCREFUSE_NUM AVC拒动数,D_TRANSACT_NUM 变压器动作数,D_TRANSCTRL_NUM 变压器AVC控制数,
//D_TRANSFAIL_NUM 变压器拒动数,D_CPACT_NUM 电容动作数,D_CPCTRL_NUM 电容AVC控制数,D_VOLOUTEVENT 电压越限事件数,
//D_COSOUTEVENT 无功越限事件数,D_LOCKEVENTNUM 闭锁事件数,D_AVCEVENTNUM AVC越限事件数,D_AVCCTRLEVENTNUM AVC控制事件数
//from avc_daysystem where d_id={0} and to_char(d_time,'yyyy-mm-dd')='{1}' and rownum=1 order by d_time desc",
//GlobalInfo.selStationID, GlobalInfo.hisDt.ToString("yyyy-MM-dd"));
//            dt = odb.GetDt(m_szSQL);
//            if (dt == null || dt.Rows.Count == 0)
//                return;

//            for (int i = 0; i < dt.Columns.Count; i++ )
//            {
//                listView.col
//            }


            string szTmp = string.Format("from avc_daysystem where d_id={0} and to_char(d_time,'yyyy-mm-dd')='{1}' and rownum=1 order by d_time desc", GlobalInfo.selStationID, GlobalInfo.hisDt.ToString("yyyy-MM-dd"));

            m_szSQL = string.Format(@"select * from (select 1,'AVC运行时间' 名称,D_AVCRUNTIME 数量 {0})
union select * from (select 2,'AVC退出运行时间',D_AVCOUTTIME {0})
union select * from (select 3,'AVC控制退出时间',D_AVCOPENTIME {0})
union select * from (select 4,'电压运行时长',D_VOLRUNTIME {0})
union select * from (select 5,'电压越限时长',D_VOLOUTTIME {0})
union select * from (select 6,'无功运行时长',D_COSRUNTIME {0})
union select * from (select 7,'无功越限时长',D_COSOUTTIME {0})
union select * from (select 8,'AVC日降损量',D_LOSSDEC {0})
union select * from (select 9,'系统设备运行时长',D_DEVRUNTIME {0})
union select * from (select 10,'设备闭锁时长',D_LOCKTIME {0})
union select * from (select 11,'系统动作数',D_ALLACT_NUM {0})
union select * from (select 12,'AVC控制数',D_AVCCTRL_NUM {0})
union select * from (select 13,'AVC拒动数',D_AVCREFUSE_NUM {0})
union select * from (select 14,'变压器动作数',D_TRANSACT_NUM {0})
union select * from (select 15,'变压器AVC控制数',D_TRANSCTRL_NUM {0})
union select * from (select 16,'变压器拒动数',D_TRANSFAIL_NUM {0})
union select * from (select 17,'电容动作数',D_CPACT_NUM {0})
union select * from (select 18,'电容AVC控制数',D_CPCTRL_NUM {0})
union select * from (select 19,'电压越限事件数',D_VOLOUTEVENT {0})
union select * from (select 20,'无功越限事件数',D_COSOUTEVENT {0})
union select * from (select 21,'闭锁事件数',D_LOCKEVENTNUM {0})
union select * from (select 22,'AVC越限事件数',D_AVCEVENTNUM {0})
union select * from (select 23,'AVC控制事件数',D_AVCCTRLEVENTNUM {0})", szTmp);

            dt = odb.GetDt(m_szSQL);
            if (dt == null || dt.Rows.Count == 0)
                return;

            listView.ItemsSource = dt.DefaultView;
        }
    }
}

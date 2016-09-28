using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using VoltageQ.CommonFunc;
using System.Data;
//using VoltageQ.Windows;

namespace VoltageQ.ViewModels
{
    class MainWindowModel : ViewModel
    {
        OracleDataBase odb = new OracleDataBase();
        protected override void OnViewLoaded()
        {

            //string id, svg;
            //DataTable dt = odb.GetDt("select m_id,m_svg from avc_station");
            //if (dt != null && dt.Rows.Count > 0)
            //{
            //    for (int i = 0; i < dt.Rows.Count; i++)
            //    {
            //        id = dt.Rows[i]["m_id"].ToString();
            //        svg = dt.Rows[i]["m_svg"].ToString();
            //        if (GlobalInfo.dicIdToSvgName.ContainsKey(id) == false)
            //        {
            //            GlobalInfo.dicIdToSvgName.Add(id, svg);
            //        }
            //    }
            //}

            DataTable dt = odb.GetDt("select m_id,m_name,m_svg from avc_syszone where m_id=0");
            if (dt != null && dt.Rows.Count > 0)
            {
                GlobalInfo.selStationID = dt.Rows[0]["m_id"].ToString();
                GlobalInfo.GroupTitleChoose = GlobalInfo.selStationName = dt.Rows[0]["m_name"].ToString();
                GlobalInfo.DefaultSvgPth = dt.Rows[0]["m_svg"].ToString();
            }

            base.OnViewLoaded();
            Navigate("WelcomeControl");
        }
    }
}

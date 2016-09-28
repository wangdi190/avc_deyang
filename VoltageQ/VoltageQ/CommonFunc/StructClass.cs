using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Reflection;
using System.Globalization;

namespace VoltageQ.CommonFunc
{

    public class GlobalInfo
    {
        public static bool bFirstStart=true;
        public static string selStationID="0";
        public static string selStationName = "全系统电网";
        public static string WebPath = System.Configuration.ConfigurationSettings.AppSettings["WebHttp"];

        public static string DefaultSvgPth;

        public static string GroupTitleChoose = "全系统电网";

        public static bool bReal = true; //true Real  false His
        public static DateTime hisDt=DateTime.Today; //
    }

    //线路表
    public class ST_Line
    {
        public string m_id { get; set; }  //线路标识
        //public string m_stationf { get; set; }  //首端厂站标识
        //public string m_stationt { get; set; }  //末端厂站标识
        //public string m_name { get; set; }  //厂站名称
        public float m_vl { get; set; }  //电压等级标识
        public float m_s  { get; set; }  //maxp
        public float m_pf { get; set; }           //首端有功
        public float m_qf { get; set; }           //首端无功
        public float m_pt { get; set; }           //末端有功
        public float m_qt { get; set; }           //末端无功
    }

    public class ST_Tfm
    {
        public string m_id { get; set; }  //标识
        public string m_station { get; set; }
        public float m_s { get; set; }
        public float m_p { get; set; }
        public float m_cos { get; set; } 
    }

    //开关表 刀闸表
    public class ST_Breaker
    {
        public string m_id { get; set; }  //
        public string m_name { get; set; }  //名称
        public int m_runsta { get; set; }  //物理连接节点
        //public int m_oldsta { get; set; }  //物理连接节点
    }

    //母线表
    public class ST_Bus
    {
        public string m_id { get; set; }  //
        public double m_vl { get; set; }  //电压等级
        public double m_vol { get; set; }  //当前电压
    }

    //基准电压表
    public class Basevoltage
    {
        public string mrid { get; set; }  //
        public string name { get; set; }  //名称
        public float nomkv { get; set; }  //基准电压
    }

    //厂站表
    public class ST_Substation
    {
        //public string m_time { get; set; }
        public string m_id { get; set; }
        //public string m_zone { get; set; }
        //public string m_name { get; set; }
        public float m_s { get; set; }
        public float m_runs { get; set; }
    }

    public class ST_Load
    {
        public string m_id { get; set; }
        public float m_p { get; set; }           //有功
        public float m_q { get; set; }           //无功
    }

    public class ConvertHelper<T> where T : new()
    {
        public static List<T> ConvertToModel(DataTable dt)
        {
            // 定义集合
            List<T> ts = new List<T>();

            // 获得此模型的类型
            Type type = typeof(T);

            string tempName = "";

            foreach (DataRow dr in dt.Rows)
            {
                T t = new T();

                // 获得此模型的公共属性
                PropertyInfo[] propertys = t.GetType().GetProperties();

                foreach (PropertyInfo pi in propertys)
                {
                    tempName = pi.Name;

                    // 检查DataTable是否包含此列
                    if (dt.Columns.Contains(tempName))
                    {
                        // 判断此属性是否有Setter
                        if (!pi.CanWrite) continue;

                        object value = dr[tempName];
                        if (value != DBNull.Value)
                        {
                            pi.SetValue(t, Convert.ChangeType(value, pi.PropertyType, CultureInfo.CurrentCulture), null);
                        }
                    }
                }
                ts.Add(t);
            }
            return ts;
        }
    }
}

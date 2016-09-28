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
using System.Data;
using VoltageQ.CommonFunc;
using System.Windows.Threading;

namespace VoltageQ.Controls
{
    /// <summary>
    /// RealDetailControl.xaml 的交互逻辑
    /// </summary>
    public partial class RealDetailControl : UserControl
    {
        OracleDataBase odb = new OracleDataBase();
        public DataTable data;
        DispatcherTimer timeTimer = new DispatcherTimer();

        public RealDetailControl()
        {
            InitializeComponent();

            
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 5);
            timeTimer.Start();
        }

        void timeTimer_Tick(object sender, EventArgs e)
        {
            UpdateSQL(-21);
        }


        List<string> name_system = new List<string>();
        List<string> name_zone = new List<string>();
        List<string> name_station = new List<string>();
        List<string> name_voltage = new List<string>();

        

        string m_szSQL_system, m_szSQL_zone, m_szSQL_station, m_szSQL_voltage;
        string m_szTmp;
        public void AddItem(int type, string szName)
        {
            if (type == 1)
                name_system.Add(szName);
            else if (type == 2)
                name_zone.Add(szName);
            else if (type == 3)
                name_station.Add(szName);
            else if (type == 4)
                name_voltage.Add(szName);

            UpdateSQL(type);
        }

        public void DeleteItem(int type, string szName)
        {
            if (type == 1)
            {
                for (int i = 0; i < name_system.Count; i++)
                {
                    if (name_system.ElementAt(i) == szName)
                    {
                        name_system.RemoveAt(i);
                        break;
                    }
                }
            }
            else if (type == 2)
            {
                for (int i = 0; i < name_zone.Count; i++)
                {
                    if (name_zone.ElementAt(i) == szName)
                    {
                        name_zone.RemoveAt(i);
                        break;
                    }
                }
            }

            else if (type == 3)
            {
                for (int i = 0; i < name_station.Count; i++)
                {
                    if (name_station.ElementAt(i) == szName)
                    {
                        name_station.RemoveAt(i);
                        break;
                    }
                }
            }

            else if (type == 4)
            {
                for (int i = 0; i < name_voltage.Count; i++)
                {
                    if (name_voltage.ElementAt(i) == szName)
                    {
                        name_voltage.RemoveAt(i);
                        break;
                    }
                }
            }

            UpdateSQL(type);
        }

        void UpdateSQL(int type)
        {
            
            if (type == 1 || type==-21)
            {
                m_szTmp = "";
                for (int i = 0; i < name_system.Count; i++)
                {
                    if (i < name_system.Count - 1)
                        m_szTmp += "'" + name_system.ElementAt(i) + "'" + ",";
                    else
                        m_szTmp += "'" + name_system.ElementAt(i) + "'";
                }
                m_szSQL_system = string.Format("select R_AVCSTA,R_AVCCTRLSTA,R_SESTA,R_ISLAND,R_NAME,R_OUTBUSNUM,R_OUTCOSNUM,R_LOCKNUM from avc_realsystem where r_type=1 and r_isreal=1 and r_name in ({0})", m_szTmp);

                data = odb.GetDt(m_szSQL_system);
                if (data == null)
                    return;

                list_system.ItemsSource = data.DefaultView;

            }
            if (type == 2 || type == -21)
            {
                m_szTmp = "";
                for (int i = 0; i < name_zone.Count; i++)
                {
                    if (i < name_zone.Count - 1)
                        m_szTmp += "'" + name_zone.ElementAt(i) + "'" + ",";
                    else
                        m_szTmp += "'" + name_zone.ElementAt(i) + "'";
                }
                m_szSQL_zone = string.Format("select R_AVCSTA,R_AVCCTRLSTA,R_SESTA,R_ISLAND,R_NAME,R_OUTBUSNUM,R_OUTCOSNUM,R_LOCKNUM from avc_realsystem where r_type=2 and r_isreal=1 and r_name in ({0})", m_szTmp);

                data = odb.GetDt(m_szSQL_zone);
                if (data == null)
                    return;

                list_zone.ItemsSource = data.DefaultView;

            }
            if (type == 3 || type == -21)
            {
                m_szTmp = "";
                for (int i = 0; i < name_station.Count; i++)
                {
                    if (i < name_station.Count - 1)
                        m_szTmp += "'" + name_station.ElementAt(i) + "'" + ",";
                    else
                        m_szTmp += "'" + name_station.ElementAt(i) + "'";
                }
                m_szSQL_station = string.Format("select R_AVCSTA,R_AVCCTRLSTA,R_SESTA,R_ISLAND,R_NAME,R_OUTBUSNUM,R_OUTCOSNUM,R_LOCKNUM from avc_realsystem where r_type=3 and r_isreal=1 and r_name in ({0})", m_szTmp);

                data = odb.GetDt(m_szSQL_station);
                if (data == null)
                    return;

                list_station.ItemsSource = data.DefaultView;
            }
            if (type == 4 || type == -21)
            {
                m_szTmp = "";
                for (int i = 0; i < name_voltage.Count; i++)
                {
                    if (i < name_voltage.Count - 1)
                        m_szTmp += "'" + name_voltage.ElementAt(i) + "'" + ",";
                    else
                        m_szTmp += "'" + name_voltage.ElementAt(i) + "'";
                }
                m_szSQL_voltage = string.Format("select R_AVCSTA,R_AVCCTRLSTA,R_SESTA,R_ISLAND,R_NAME,R_OUTBUSNUM,R_OUTCOSNUM,R_LOCKNUM from avc_realsystem where r_type=4 and r_isreal=1 and r_name in ({0})", m_szTmp);

                data = odb.GetDt(m_szSQL_voltage);
                if (data == null)
                    return;

                list_voltage.ItemsSource = data.DefaultView;
            }
        }
    }
}

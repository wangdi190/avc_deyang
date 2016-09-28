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
using DevExpress.Xpf.NavBar;
using DevExpress.Xpf.DemoBase;
using System.Windows.Markup;
using VoltageQ.Windows;
using System.Diagnostics;

namespace VoltageQ.Views
{
    /// <summary>
    /// ChooseView.xaml 的交互逻辑
    /// </summary>
    public partial class ChooseView : UserControl
    {
        
        public static DataTable data;
   //     public DataTable Data { get { return data; } set { data = value; } }
        OracleDataBase odb = new OracleDataBase();
        public string m_szSQL;
        

        public ChooseView()
        {
            InitializeComponent();
            system_view.Hide = false;
            zone_view.Hide = true;
            station_view.Hide = true;

            //system_frame.Navigate(new Uri("SystemView.xaml", UriKind.Relative));
            //zone_frame.Navigate(new Uri("ZoneView.xaml", UriKind.Relative));
            //station_frame.Navigate(new Uri("StationView.xaml", UriKind.Relative));
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            /*m_szSQL = @"select b.m_id as ZoneID,b.m_name as ZoneName,a.m_name as StationName,a.m_id as StationID from avc_station a,avc_syszone b where a.m_zone=b.m_id union
select 9999,'全系统电网',m_name,m_id from avc_syszone where (m_220num>0 or m_110num>0) and m_id<>9999";*/

            m_szSQL = @"select b.m_id as ZoneID,b.m_name as ZoneName,a.m_name as StationName,a.m_id as StationID from avc_station a,avc_syszone b where a.m_zone=b.m_id union
select 0,'全系统电网',m_name,m_id from avc_syszone where (m_220num>0 or m_110num>0) order by stationid";

            data = odb.GetDt(m_szSQL);
            if (data != null)
                navbar.ItemsSource = data.DefaultView;


            for (int i = 0; i < navbar.Groups.Count; i++ )
            {
                NavBarGroup group = (NavBarGroup)navbar.Groups.ElementAt(i);
                //group.Click += new EventHandler(NavBarGroup_Click);
                for (int j = 0; j < group.Items.Count; j++)
                {
                    NavBarItem item = (NavBarItem)navbar.Groups.ElementAt(i).Items.ElementAt(j);

                    
                    if (group.Header.ToString() == "全系统电网")
                        item.Click += new EventHandler(NavBarZoneItem_Click);
                    else
                    {
                        item.Click += new EventHandler(NavBarStationItem_Click);
                    }
                }
            }

            bool bFound = false;

            for (int i = 0; i < navbar.Groups.Count; i++)
            {
                NavBarGroup group = (NavBarGroup)navbar.Groups.ElementAt(i);


                for (int j = 0; j < group.Items.Count; j++)
                {
                    NavBarItem item = (NavBarItem)navbar.Groups.ElementAt(i).Items.ElementAt(j);
                    if (group.Header.ToString() == "全系统电网")//GlobalInfo.GroupTitleChoose)
                    {
                        if (item.Content.ToString() == GlobalInfo.selStationName)
                        {
                            NavBarZoneItem_Click(item, e);
                            bFound = true;
                            break;
                        }
                    }
                    else
                    {
                        if (item.Content.ToString() == GlobalInfo.selStationName)
                        {
                            NavBarStationItem_Click(item, e);
                            bFound = true;
                            break;
                        }
                    }
                }

                if (bFound)
                    break;
            }

            TogSwitch.IsChecked = GlobalInfo.bReal;
            
        }

        //void NavBarGroup_Click(object sender, EventArgs e)
        //{
        //    NavBarGroup group = sender as NavBarGroup;
        //    GlobalInfo.GroupTitleChoose = group.Header.ToString();
        //}

        //string TitleText
        //{
        //    set
        //    {
        //        if(GlobalInfo.bReal)
        //            Cur_Choose.Text = value;
        //        else
        //            Cur_Choose.Text = value + GlobalInfo.hisDt.ToString("yyyy-MM-dd");
        //    }
        //}

        void NavBarZoneItem_Click(object sender, EventArgs e)
        {
            
            NavBarItem item = sender as NavBarItem;
           
            GlobalInfo.GroupTitleChoose = (item.Parent as NavBarGroup).Header.ToString();

            GlobalInfo.selStationName = Cur_Choose.Text = item.Content.ToString();
            GlobalInfo.selStationID = item.Tag.ToString();
            if (GlobalInfo.bReal == true)
            {
                if (GlobalInfo.selStationID == "0")
                {
                    system_view.Hide = false;
                    zone_view.Hide = true;
                    station_view.Hide = true;
                }
                else
                {
                    system_view.Hide = true;
                    zone_view.Hide = false;
                    station_view.Hide = true;
                }
                hiszone_view.Hide = true;
                hisstation_view.Visibility = Visibility.Collapsed;
            }
            else
            {
                system_view.Hide = true;
                zone_view.Hide = true;
                station_view.Hide = true;
                hiszone_view.Hide = false;
                hisstation_view.Visibility = Visibility.Collapsed;
            }
        }


        void NavBarStationItem_Click(object sender, EventArgs e)
        {
            NavBarItem item = sender as NavBarItem;
            GlobalInfo.GroupTitleChoose = (item.Parent as NavBarGroup).Header.ToString();

            GlobalInfo.selStationName = Cur_Choose.Text = item.Content.ToString();
            GlobalInfo.selStationID = item.Tag.ToString();
            if (GlobalInfo.bReal == true)
            {
                system_view.Hide = true;
                zone_view.Hide = true;
                station_view.Hide = false;
                hiszone_view.Hide = true;
                hisstation_view.Visibility = Visibility.Collapsed;
            }
            else
            {
                system_view.Hide = true;
                zone_view.Hide = true;
                station_view.Hide = true;
                hiszone_view.Hide = true;
                hisstation_view.Visibility = Visibility.Visible;
            }
            
        }

        private void EnterStation_Click(object sender, RoutedEventArgs e)
        {
            bool bFound = false;
            DataTable dtStation = odb.GetDt("select m_id,m_svg from avc_station");
            if (dtStation != null && dtStation.Rows.Count > 0)
            {
                DataRow[] dr = dtStation.Select(string.Format("m_id={0}", GlobalInfo.selStationID));
                if (dr.Length > 0)
                {
                    GlobalInfo.DefaultSvgPth = dr[0]["m_svg"].ToString();
                    bFound = true;
                }
            }

            if (bFound == false)
            {
                DataTable dtZone = odb.GetDt("select m_id,m_svg from avc_syszone");
                if (dtZone != null && dtZone.Rows.Count > 0)
                {
                    DataRow[] dr = dtZone.Select(string.Format("m_id={0}", GlobalInfo.selStationID));
                    if (dr.Length > 0)
                    {
                        GlobalInfo.DefaultSvgPth = dr[0]["m_svg"].ToString();
                        bFound = true;
                    }
                }
            }

            if (bFound == true)
            {
                if (GlobalInfo.DefaultSvgPth != "")
                    EnterStation.CommandParameter = "SvgView";
                else
                    MessageBox.Show("数据库中没有对应的厂站svg");
            }

            else
                MessageBox.Show("数据库中没有对应的厂站");
        }

        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    Button btn = sender as Button;
        //    if (btn.Tag.ToString() == "Real")
        //    {
        //        GlobalInfo.bReal = true;
        //        dtPicker.Visibility = Visibility.Hidden;

        //        if (GlobalInfo.GroupTitleChoose == "全系统电网")
        //        {
                    
        //            station_view.Hide = true;
        //            hiszone_view.Hide = true;
        //            hisstation_view.Visibility = Visibility.Collapsed;

        //            if (GlobalInfo.selStationID == "0")
        //            {
        //                system_view.Hide = false;
        //                zone_view.Hide = true;
        //            }
        //            else
        //            {
        //                system_view.Hide = true;
        //                zone_view.Hide = false;
        //            }
        //        }
        //        else
        //        {
        //            system_view.Hide = true;
        //            zone_view.Hide = true;
        //            station_view.Hide = false;
        //            hiszone_view.Hide = true;
        //            hisstation_view.Visibility = Visibility.Collapsed;
        //        }
                

        //    }
        //    else if (btn.Tag.ToString() == "His")
        //    {
        //        GlobalInfo.bReal = false;
        //        dtPicker.SelectedDate = GlobalInfo.hisDt;
        //        dtPicker.Visibility = Visibility.Visible;
        //        ChangeToHisView();
        //    }
        //}

        private void TogSwitch_Click(object sender, RoutedEventArgs e)
        {
            if (TogSwitch.IsChecked == true)
            {
                GlobalInfo.bReal = true;
                dtPicker.Visibility = Visibility.Hidden;

                if (GlobalInfo.GroupTitleChoose == "全系统电网")
                {

                    station_view.Hide = true;
                    hiszone_view.Hide = true;
                    hisstation_view.Visibility = Visibility.Collapsed;

                    if (GlobalInfo.selStationID == "0")
                    {
                        system_view.Hide = false;
                        zone_view.Hide = true;
                    }
                    else
                    {
                        system_view.Hide = true;
                        zone_view.Hide = false;
                    }
                }
                else
                {
                    system_view.Hide = true;
                    zone_view.Hide = true;
                    station_view.Hide = false;
                    hiszone_view.Hide = true;
                    hisstation_view.Visibility = Visibility.Collapsed;
                }
            }
            else
            {
                GlobalInfo.bReal = false;
                dtPicker.SelectedDate = GlobalInfo.hisDt;
                dtPicker.Visibility = Visibility.Visible;
                ChangeToHisView();
            }
        }

        private void dtPicker_SelectedDateChanged(object sender, SelectionChangedEventArgs e)
        {
            GlobalInfo.hisDt = dtPicker.SelectedDate.Value;
            ChangeToHisView();
        }

        void ChangeToHisView()
        {
            if (GlobalInfo.bReal == false)
            {
                system_view.Hide = true;
                zone_view.Hide = true;
                station_view.Hide = true;
                if (GlobalInfo.GroupTitleChoose == "全系统电网")
                {
                    hiszone_view.Hide = false;
                    hisstation_view.Visibility = Visibility.Collapsed;
                }
                else
                {
                    hiszone_view.Hide = true;
                    hisstation_view.Visibility = Visibility.Visible;
                }
            }
        }

        
    }

    public class CategoryIDToGroupConverter : MarkupExtension, IValueConverter
    {
        #region IValueConverter Members
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {

            DataRow[] rows = ChooseView.data.Select("ZONEID = " + System.Convert.ToString(value));
            if (rows.Count() > 0)
                return rows[0][(string)parameter];
            return null;
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
        #endregion

        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            return this;
        }
    }
}

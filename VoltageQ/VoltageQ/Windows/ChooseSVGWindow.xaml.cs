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
using System.Windows.Shapes;
using System.Windows.Markup;
using System.Data;
using DevExpress.Xpf.NavBar;
using VoltageQ.CommonFunc;

namespace VoltageQ.Windows
{
    /// <summary>
    /// ChooseSVGWindow.xaml 的交互逻辑
    /// </summary>
    public partial class ChooseSVGWindow : Window
    {
        public static DataTable data;
        OracleDataBase odb = new OracleDataBase();
        public ChooseSVGWindow()
        {
            InitializeComponent();

            string m_szSQL = @"select b.m_id as ZoneID,b.m_name as ZoneName,a.m_name as StationName,a.m_svg as StationSVG from avc_station a,avc_syszone b where a.m_zone=b.m_id union
select 0,'全系统电网',m_name,m_svg from avc_syszone where (m_220num>0 or m_110num>0)";

            data = odb.GetDt(m_szSQL);
            if (data != null)
                navbar.ItemsSource = data.DefaultView;

            for (int i = 0; i < navbar.Groups.Count; i++)
            {
                NavBarGroup group = (NavBarGroup)navbar.Groups.ElementAt(i);
                group.Click += new EventHandler(NavBarGroup_Click);
                for (int j = 0; j < group.Items.Count; j++)
                {
                    NavBarItem item = (NavBarItem)navbar.Groups.ElementAt(i).Items.ElementAt(j);
                    item.Click += new EventHandler(item_Click);

                    

                    //if (group.Header.ToString() == "全系统电网")
                    //    item.Click += new EventHandler(NavBarZoneItem_Click);
                    //else
                    //{
                    //    item.Click += new EventHandler(NavBarStationItem_Click);
                    //}
                }
            }

        }

        void NavBarGroup_Click(object sender, EventArgs e)
        {
            NavBarGroup group = sender as NavBarGroup;
            GlobalInfo.GroupTitleChoose = group.Header.ToString();
        }

        void item_Click(object sender, EventArgs e)
        {
            NavBarItem item = sender as NavBarItem;
            if (item.Tag != null)
            {
                MessageBoxResult result = MessageBox.Show("进入该厂站svg文件", "VoltageQ", MessageBoxButton.YesNo);

                if (MessageBoxResult.Yes == result)
                {
                    GlobalInfo.DefaultSvgPth = item.Tag.ToString();
                    GlobalInfo.selStationName = item.Content.ToString();


                    DataTable dt = odb.GetDt(string.Format("select * from (select m_id,m_name from avc_station union select m_id,m_name from avc_syszone) where m_name='{0}'", item.Content));
                    if (dt != null && dt.Rows.Count > 0)
                    {
                        GlobalInfo.selStationID = dt.Rows[0]["m_id"].ToString();
                    }
                    this.Close();
                }
            }
            else
                MessageBox.Show("没有填写对应的svg文件");
        }
    }

    public class CategoryIDToGroupConverter : MarkupExtension, IValueConverter
    {
        #region IValueConverter Members
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {

            DataRow[] rows = ChooseSVGWindow.data.Select("ZONEID = " + System.Convert.ToString(value));
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

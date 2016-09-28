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
using System.Collections.ObjectModel;
using VoltageQ.ViewModels;
using System.Data;
using VoltageQ.CommonFunc;
using DevExpress.Xpf.LayoutControl;
using VoltageQ.Windows;


namespace VoltageQ.Views
{
    /// <summary>
    /// RealRunControl.xaml 的交互逻辑
    /// </summary>
    public partial class RealRunControl : UserControl
    {
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        double width = 0.0, height = 0.0;

        public RealRunControl()
        {
            InitializeComponent();
            //this.DataContext = new RealRunControlModel();
        }

        private void layoutControl_Loaded(object sender, RoutedEventArgs e)
        {
            width = laygrid.RenderSize.Width / 2 - 20;
            height = laygrid.RowDefinitions.ElementAt(0).ActualHeight / 2 - 20;

            foreach (var child in layoutControl.GetLogicalChildren(false))
            {
                child.Width = width;
                child.Height = height;
            }

            //1系统，2区域，3厂站，4电压等级
            string m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=2 order by r_name";
            data = odb.GetDt(m_szSQL);
            if (data != null)
                tree_zone.ItemsSource = data.DefaultView;

            m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=3  order by r_name";
            data = odb.GetDt(m_szSQL);
            if (data != null)
                tree_station.ItemsSource = data.DefaultView;

            m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=4  order by r_name";
            data = odb.GetDt(m_szSQL);
            if (data != null)
                tree_voltage.ItemsSource = data.DefaultView;
        }

        private void layoutControl_MaximizedElementChanged(object sender, DevExpress.Xpf.Core.ValueChangedEventArgs<FrameworkElement> e)
        {

            double jbwidth = width, jbheight = height;
            if (layoutControl.MaximizedElement != null)
            {
                jbwidth = 300;
                jbheight = 300;
            }

            foreach (var child in layoutControl.GetLogicalChildren(false))
            {
                if (child == layoutControl.MaximizedElement)
                {
                    continue;
                }
                child.Width = jbwidth;
                child.Height = jbheight;
            }

            if (layoutControl.MaximizedElement == null) //正常显示4个
            {
                realChartControl.Show();
                dayChartControl.Show();
                //dayCurveControl.Show();
            }
            else
            {
                realChartControl.Hide();
                dayChartControl.Hide();
                //dayCurveControl.Hide();
                if (layoutControl.MaximizedElement.Tag.ToString() == "实时指标")
                    realChartControl.Show();
                else if (layoutControl.MaximizedElement.Tag.ToString() == "当日指标")
                    dayChartControl.Show();
                //else if (layoutControl.MaximizedElement.Tag.ToString() == "当日明细")
                //    dayCurveControl.Show();
            }
        }


        private void Label_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Label lab = sender as Label;
            DevExpress.Xpf.LayoutControl.GroupBox box = (DevExpress.Xpf.LayoutControl.GroupBox)lab.Parent;

            if (box.State == GroupBoxState.Normal)
                box.State = GroupBoxState.Maximized;
            else
                box.State = GroupBoxState.Normal;
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            CheckBox box = sender as CheckBox;

            realChartControl.AddBar(Convert.ToInt32(box.Tag), box.Content.ToString());
            dayChartControl.AddBar(Convert.ToInt32(box.Tag), box.Content.ToString());
            //dayCurveControl.AddCurve(Convert.ToInt32(box.Tag), box.Content.ToString());
            realDetailControl.AddItem(Convert.ToInt32(box.Tag), box.Content.ToString());
        }

        private void CheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            CheckBox box = sender as CheckBox;
            realChartControl.RemoveBar(box.Content.ToString());
            dayChartControl.RemoveBar(box.Content.ToString());
            //dayCurveControl.DeleteCurve(Convert.ToInt32(box.Tag), box.Content.ToString());
            realDetailControl.DeleteItem(Convert.ToInt32(box.Tag), box.Content.ToString());
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Point pos = Mouse.GetPosition(e.Source as FrameworkElement);
            Point pos_screen = (e.Source as FrameworkElement).PointToScreen(pos);

            UpTextWindow win = new UpTextWindow();
            win.Width = 700;
            win.Height = 250;
            win.Left = pos_screen.X - win.Width;
            win.Top = pos_screen.Y - win.Height;

            win.Show();
            //win.ShowDialog();
        }
    }
}

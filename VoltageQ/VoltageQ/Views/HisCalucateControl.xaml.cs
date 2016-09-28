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
using System.Windows.Media.Effects;
using VoltageQ.Controls;

namespace VoltageQ.Views
{
    /// <summary>
    /// HisCalucateControl.xaml 的交互逻辑
    /// </summary>
    public partial class HisCalucateControl : UserControl
    {
        DropShadowEffect MouseEnter_shadow = new DropShadowEffect() { BlurRadius = 16, ShadowDepth = 15, Opacity = 0.5, Direction = 270 };
        DropShadowEffect MouseLeave_shadow = new DropShadowEffect() { BlurRadius = 16, ShadowDepth = 1, Opacity = 0.5, Direction = 270 };


        public HisCalucateControl()
        {
            InitializeComponent();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            double width = TabControl.ActualWidth;
            double height = TabControl.ActualHeight;

            //SvgView svg = new SvgView();
            //svg.Width = width / 2;
            //svg.Height = height;
            //TabControl.AddTab(svg);

            HisNinePointControl ele = new HisNinePointControl();
            ele.Width = width/2;
            ele.Height = height;
            TabControl.AddTab(ele);

            RealChartControl ele1 = new RealChartControl();
            ele1.Width = width / 2;
            ele1.Height = height;
            TabControl.AddTab(ele1);
            
            TabControl.NumberOfTabs = 2;
            TabControl.AnimationDuration = 2000;
        }

        private void Item_Loaded(object sender, RoutedEventArgs e)
        {
            FrameworkElement ele = (FrameworkElement)sender;
            ele.Effect = MouseLeave_shadow;
        }

        private void Item_MouseEnter(object sender, MouseEventArgs e)
        {
            FrameworkElement ele = (FrameworkElement)sender;
            ele.Effect = MouseEnter_shadow;
        }

        private void Item_MouseLeave(object sender, MouseEventArgs e)
        {
            FrameworkElement ele = (FrameworkElement)sender;
            ele.Effect = MouseLeave_shadow;
        }

        private void Item_MouseDown(object sender, MouseButtonEventArgs e)
        {
            FrameworkElement ele = (FrameworkElement)sender;

            TabControl.AnimationDuration = 1;
            int nIndex = Convert.ToInt32(ele.Tag);
            if(nIndex>=0 && nIndex<7)
                TabControl.SpinToIndex(nIndex);
        }

        private void TabControl_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            TabControl.AnimationDuration = 2000;
            if (e.Delta > 0)
            {
                TabControl.SpinToNext();
            }
            else
            {
                TabControl.SpinToPrevious();
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            FrameworkElement btn = sender as FrameworkElement;

            TabControl.AnimationDuration = 2000;
            if (btn.Tag.ToString() == "next")
                TabControl.SpinToNext();
            else if (btn.Tag.ToString() == "prev")
                TabControl.SpinToPrevious();
        }

        private void Button_MouseEnter(object sender, MouseEventArgs e)
        {
            FrameworkElement ele = sender as FrameworkElement;
            ele.Opacity = 1;
        }

        private void Button_MouseLeave(object sender, MouseEventArgs e)
        {
            FrameworkElement ele = sender as FrameworkElement;
            ele.Opacity = 0.6;
        }

        

        
    }
}

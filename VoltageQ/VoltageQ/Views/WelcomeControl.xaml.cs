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
using VoltageQ.Windows;
using VoltageQ.CommonFunc;

namespace VoltageQ.Views
{
    /// <summary>
    /// WelcomeControl.xaml 的交互逻辑
    /// </summary>
    public partial class WelcomeControl : UserControl
    {
        //static bool bFirstStart=true;
        public WelcomeControl()
        {
            InitializeComponent();
            jieshao.Text = @"       地区电压无功实时评估系统结合了无功电压的优化目标，对控制策略对各目标实现的情况以及AVC运行的情况进行评估。在考虑系统无功电压运行的经济性、安全性以及AVC动作合理性、正确性的基础上，采用人工与智能结合的模糊综合评价方法，对某电网的AVC给出的控制策略进行全面而综合的评价，得出了简洁、直观的评价结果，为地区AVC控制系统以及电网无功电压的运行提供参考。";
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            //if (GlobalInfo.bFirstStart == false)
            //{
            //    layoutControl.Visibility = Visibility.Visible;
            //    login.Visibility = Visibility.Hidden;
            //}
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void Login_Click(object sender, RoutedEventArgs e)
        {
            //if (UserName.Text == "power" && UserPassword.Password == "sa")
            //{
            //    layoutControl.Visibility = Visibility.Visible;
            //    login.Visibility = Visibility.Hidden;
            //    GlobalInfo.bFirstStart = false;
            //}
            //else
            //    MessageBox.Show("您输入的用户名或密码不正确\n请重新输入");
        }
    }
}

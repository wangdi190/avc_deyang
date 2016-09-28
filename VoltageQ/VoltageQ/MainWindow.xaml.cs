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
using VoltageQ.CommonFunc;

namespace VoltageQ
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            //GlobalInfo.svgFiles = System.IO.Directory.GetFiles(System.Environment.CurrentDirectory + "\\SVG");
            InitializeComponent();
            this.DataContext = new MainWindowModel();

            
        }
    }
}

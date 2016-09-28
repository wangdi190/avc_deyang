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
using DevExpress.Xpf.Core;

namespace VoltageQ.Windows
{
    /// <summary>
    /// UpTextWindow.xaml 的交互逻辑
    /// </summary>
    public partial class UpTextWindow : DXWindow
    {
        public UpTextWindow()
        {
            InitializeComponent();
        }

        private void DXWindow_Deactivated(object sender, EventArgs e)
        {
            Close();
        }
    }
}

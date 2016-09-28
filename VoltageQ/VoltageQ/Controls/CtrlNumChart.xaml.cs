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
using DynSceneLibrary;

namespace VoltageQ.Controls
{
    /// <summary>
    /// CtrlNumChart.xaml 的交互逻辑
    /// </summary>
    public partial class CtrlNumChart : UserControl
    {
        public CtrlNumChart()
        {
            //_object = obj;
            InitializeComponent();
            //if (obj != null)
            //    chartflag.Text = obj.ObjectName;
        }

        public void UpdateData(string _name, int _volnum, int _cosnum, int _locknum, int _ctrlnum)
        {
            chartflag.Text = _name;
            volnum.Value = (double)_volnum;
            cosnum.Value = (double)_cosnum;
            locknum.Value = (double)_locknum;
            ctrlnum.Value = (double)_ctrlnum;
        }
        //private CObjectPosition _object;
        //public CObjectPosition ObjectInfo { get { return _object; } }
    }
}

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
using System.Runtime.InteropServices;
using System.Diagnostics;
using DevExpress.Xpf.Charts;

namespace VoltageQ.Controls
{
    /// <summary>
    /// DayCurveControl.xaml 的交互逻辑
    /// </summary>
    public partial class HisCurveControl : UserControl
    {
        [StructLayoutAttribute(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
        struct _HisDataUnit
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
           public float[] fvl;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
            public float[] flimit;
            public byte sta;
            public int datatime;
        }


        private DataTable data;
        OracleDataBase odb = new OracleDataBase();

        int size;

        public HisCurveControl()
        {
            InitializeComponent();
            size = Marshal.SizeOf(typeof(_HisDataUnit));
            
        }

        //byte[]转换为struct
        public static object BytesToStruct(byte[] bytes, Type strcutType, int size)
        {
            //int size = Marshal.SizeOf(strcutType);
            IntPtr buffer = Marshal.AllocHGlobal(size);
            try
            {
                Marshal.Copy(bytes, 0, buffer, size);
                return Marshal.PtrToStructure(buffer, strcutType);
            }
            finally
            {
                Marshal.FreeHGlobal(buffer);
            }
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            DataTable dt = odb.GetDt("select * from AVC_HISCURVE where data_name='220kV南华站110kV2母'");
            if (dt == null || dt.Rows.Count == 0)
                return;

            foreach (DataRow dr in dt.Rows)
            {
                LineSeries2D line = new LineSeries2D();
                byte[] bytes = (byte[])dr["data_value"];
                int nCount = Convert.ToInt32(dr["data_datanum"]);
                line.DisplayName = dr["data_name"].ToString();

                for (int i = 0; i < nCount; i++)
                {
                    SeriesPoint point = new SeriesPoint();
                    byte[] b = new byte[size];
                    Array.Copy(bytes, i * size, b, 0, size);
                    _HisDataUnit cc = (_HisDataUnit)BytesToStruct(b, typeof(_HisDataUnit), size);

                    DateTime date = new DateTime(1970, 1, 1).AddSeconds(cc.datatime);
                    point.Argument = date.ToString();
                    point.Value = cc.fvl[0];
                    line.Points.Add(point);
                }
                chart.Diagram.Series.Add(line);
            }

            
        }
    }
}

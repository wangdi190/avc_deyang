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
using System.Windows.Controls.Primitives;
using DynSceneLibrary;
using System.Windows.Media.Media3D;
using VoltageQ.CommonFunc;
using System.Windows.Threading;
using System.Text.RegularExpressions;
using System.Data;
using VoltageQ.Windows;
using System.Runtime.InteropServices;
using System.Diagnostics;
using VoltageQ.Controls;

namespace VoltageQ.Views
{
    //enum OBJECT_ELEMENT_TYPE //对象元素类型
    //{
    //    OBJECT_ELEMENT_BMP = 0,//位图
    //    OBJECT_ELEMENT_AREA = 1,//区域
    //    OBJECT_ELEMENT_LABLE = 2, //标签
    //    OBJECT_ELEMENT_SUB = 3,//厂站
    //    OBJECT_ELEMENT_LINE = 4,//线路
    //    OBJECT_ELEMENT_TFM2 = 5,//二绕组
    //    OBJECT_ELEMENT_TFM3 = 6,//三绕组
    //    OBJECT_ELEMENT_GEN = 7,//发电机
    //    OBJECT_ELEMENT_BUS = 8,//母线
    //    OBJECT_ELEMENT_SWITCH = 9,//开关
    //    OBJECT_ELEMENT_LOAD = 10,//负荷
    //    OBJECT_ELEMENT_COMPENSATOR = 11,//补偿
    //    OBJECT_ELEMENT_MEAS = 12,//量测
    //    OBJECT_ELEMENT_GROUND = 13,//地面
    //    OBJECT_ELEMENT_HEAD = 14,//头定义
    //    OBJECT_ELEMENT_SECTION = 15,//断面
    //    OBJECT_ELEMENT_SCUPBOARD = 16,//开关柜
    //    OBJECT_ELEMENT_CABLEBOX = 17,//电缆箱
    //    OBJECT_ELEMENT_OTHER = 18,//其他
    //    OBJECT_ELEMENT_NONE = 19//未知
    //};


    /// <summary>
    /// SvgView.xaml 的交互逻辑
    /// </summary>
    public partial class SvgView : UserControl
    {
        private Popup popTip = null;
        private Popup popTipBar = null;

        List<CObjectPosition> PosLineSegments = new List<CObjectPosition>();
        List<CObjectPosition> PosLines = new List<CObjectPosition>();
        List<CObjectPosition> PosStations = new List<CObjectPosition>();
        List<CObjectPosition> PosDisconnectors = new List<CObjectPosition>();
        List<CObjectPosition> PosBreakers = new List<CObjectPosition>();
        List<CObjectPosition> PosDollyBreakers = new List<CObjectPosition>();
        List<CObjectPosition> PosTfms = new List<CObjectPosition>();
        List<CObjectPosition> PosBuss = new List<CObjectPosition>();
        List<CObjectPosition> PosLoads = new List<CObjectPosition>();

        //List<Aclinedot> ldline = new List<Aclinedot>();
        List<ST_Tfm> DB_TfmList = new List<ST_Tfm>();
        List<ST_Breaker> DB_BreakerList = new List<ST_Breaker>();
        List<ST_Line> DB_LineList = new List<ST_Line>();
        List<ST_Bus> DB_BusList = new List<ST_Bus>();
        List<ST_Substation> DB_StationList = new List<ST_Substation>();
        List<ST_Load> DB_LoadList = new List<ST_Load>();
        //List<ST_Breakers> DB_StationList = new List<ST_Substation>();
        //Dictionary<string, ST_Substation> DicStation = new Dictionary<string, ST_Substation>();

        //Random rd = new Random();
        private Model3D _capturem3d;
        double val;

        OracleDataBase odb = new OracleDataBase();
        DispatcherTimer timeTimer = new DispatcherTimer();
        string m_szSQL, m_szError, m_szTmp;

        

        ContourGraph.Contour contour = new ContourGraph.Contour();

        void InitSvgEquipmentList()
        {
            //timeTimer.Stop();

            scene.MapFile = GlobalInfo.WebPath + GlobalInfo.DefaultSvgPth;
            scene.Zoom = 9;
            
            infoTitle.Content = GlobalInfo.DefaultSvgPth;

            if (PosStations != null) PosStations.Clear();
            if (PosLines != null) PosLines.Clear();
            if (PosDisconnectors != null) PosDisconnectors.Clear();
            if (PosBreakers != null) PosBreakers.Clear();
            if (PosDollyBreakers != null) PosDollyBreakers.Clear();
            if (PosBuss != null) PosBuss.Clear();
            if (PosTfms != null) PosTfms.Clear();
            if (PosLoads != null) PosLoads.Clear();

            PosStations = scene.GetElementPositions("Sensitive_Layer", null);
            PosLineSegments = scene.GetElementPositions("ACLineSegment_Layer", null);
            PosLines = scene.GetElementPositions("ACLine_Layer", null);
            PosBreakers = scene.GetElementPositions("Breaker_Layer", null);
            PosDisconnectors = scene.GetElementPositions("Disconnector_Layer", null);
            PosDollyBreakers = scene.GetElementPositions("DollyBreaker_Layer", null);
            PosBuss = scene.GetElementPositions("Bus_Layer", null);
            PosLoads = scene.GetElementPositions("Load_Layer", null);
            FilterTfms("Transformer2_Layer");
            FilterTfms("Transformer3_Layer");

            if (scene.Model3DGroup != null)
                scene.Model3DGroup.Children.Clear();

            if (Math.Abs(scene.VRCamera - 90.0) > 0.1)
                scene.VRCamera = 90;

            SampleTip.Visibility = Visibility.Hidden;
            //contour.canv.Visibility = Visibility.Hidden;

            BtnTfmBar.Tag = "0";
            BtnCtrlNum.Tag = "0";
            BtnStationBar.Tag = "0";

            
            timeTimer.Tick += new EventHandler(timeTimer_Tick);
            timeTimer.Interval = new TimeSpan(0, 0, 30);
            timeTimer.Start();

            UpdateElement();
        }

        private void Grid_Unloaded(object sender, RoutedEventArgs e)
        {
            if (timeTimer != null)
                timeTimer.Stop();
            GC.Collect();
        }

        void timeTimer_Tick(object sender, EventArgs e)
        {
            UpdateElement();
        }

        void FilterTfms(string name)
        {
            List<CObjectPosition> PosTfmsTmp = new List<CObjectPosition>();
            PosTfmsTmp = scene.GetElementPositions(name, null);
            if (PosTfmsTmp != null)
            {
                foreach (CObjectPosition pos in PosTfmsTmp)
                {
                    if (PosTfms.Count != 0)
                    {
                        CObjectPosition tmp = PosTfms.Find((CObjectPosition tfm) => tfm.ObjectID == pos.ObjectID);
                        if (tmp != null)
                        {
                            double left = tmp.ObjectPosition.Left < pos.ObjectPosition.Left ? tmp.ObjectPosition.Left : pos.ObjectPosition.Left;
                            double right = tmp.ObjectPosition.Right > pos.ObjectPosition.Right ? tmp.ObjectPosition.Right : pos.ObjectPosition.Right;
                            double bottom = tmp.ObjectPosition.Bottom > pos.ObjectPosition.Bottom ? tmp.ObjectPosition.Bottom : pos.ObjectPosition.Bottom;
                            double top = tmp.ObjectPosition.Top < pos.ObjectPosition.Top ? tmp.ObjectPosition.Top : pos.ObjectPosition.Top;
                            PosTfms.First().ObjectPosition = new Rect(left, top, right - left, bottom - top);
                        }
                        else
                            PosTfms.Insert(0, pos);
                    }
                    else
                        PosTfms.Insert(0, pos);
                }
                PosTfmsTmp.Clear();
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            ChooseSVGWindow window = new ChooseSVGWindow();
            window.ShowDialog();
            InitSvgEquipmentList();

            //Microsoft.Win32.OpenFileDialog ofd = new Microsoft.Win32.OpenFileDialog();

            //ofd.InitialDirectory = System.Environment.CurrentDirectory + "\\SVG\\";
            //ofd.DefaultExt = ".svg";
            //ofd.Filter = "svg file|*.svg";
            //if (ofd.ShowDialog() == true)
            //{
            //    GlobalInfo.DefaultSvgPth = ofd.FileName;
            //    InitSvgEquipmentList(ofd.FileName, ofd.SafeFileName);
            //}
        }

        //DynScene scene = null;
        public SvgView()
        {
            InitializeComponent();

            if (GlobalInfo.bFirstStart == true)
            {
                //scene = new DynScene() { PowerFlow =true, TextMode=0};

                //scene.TipInfo += new DynScene.TipInfoEventHandler(scene_TipInfo);
                //scene.MouseMove += new MouseEventHandler(scene_MouseMove);
                //viewPort.Viewport = scene;

                scene.AddLayerMap("DollyBreaker_Layer", 9);
                scene.AddLayerMap("ACLine_Layer", 4);
                scene.AddLayerMap("Sensitive_Layer", 3);
                GlobalInfo.bFirstStart = false;
            }

            popTip = CreateTip();
            popTipBar = CreateTipBar();

            
            //<t:HelixViewport3D  ZoomExtentsWhenLoaded="True"></t:HelixViewport3D>
            //<svg:DynScene x:Name="scene" Grid.Row="1"  TextMode="0" PowerFlow="True" TipInfo="scene_TipInfo" MouseMove="scene_MouseMove" MouseDown="scene_MouseDown"></svg:DynScene>

            //HelixViewport3D viewPort = new HelixViewport3D();

            

            

            InitSvgEquipmentList();
        }

       

        public Popup CreateTip()
        {
            Popup popTip = new Popup();
            popTip.IsOpen = false;
            popTip.PlacementTarget = scene;
            popTip.Visibility = Visibility.Visible;
            popTip.Placement = PlacementMode.Relative;

            TextBlock txt = new TextBlock();
            txt.Background = Brushes.WhiteSmoke; //new SolidColorBrush(Color.FromArgb(225, 255, 255, 255));
            txt.FontSize = 16;

            popTip.Child = txt;
            return popTip;
        }

        public Popup CreateTipBar()
        {
            Popup popTip = new Popup();
            popTip.IsOpen = false;
            popTip.PlacementTarget = scene;
            popTip.Visibility = Visibility.Visible;
            popTip.Placement = PlacementMode.Relative;

            CtrlNumChart bar = new CtrlNumChart() { Background = Brushes.WhiteSmoke };

            popTip.Child = bar;
            return popTip;
        }


        //private void scene_MouseDown(object sender, MouseButtonEventArgs e)
        //{
        //}

        Regex regex1 = new Regex("\\d*\\.ST=\\d*/LN=\\d*");
        Regex regex2 = new Regex("\\d*\\.\\d*");

        Regex regex3 = new Regex("ST=\\d*/LN=\\d*");
        Regex regex4 = new Regex("\\d*");
        
        private void scene_MouseMove(object sender, MouseEventArgs e)
        {
            string tipinfo = null;
            if (Math.Abs(scene.VRCamera - 90.0) < 0.1)
            {

                if (scene.SelectedElement != null)
                {
                    Debug.WriteLine("plane");
                    tipinfo = scene.SelectedElement;
                    string ChooseID = "null";
                    if (regex1.Match(tipinfo).Success)
                    {
                        ChooseID = tipinfo.Split('=')[2];
                    }
                    else if (regex2.Match(tipinfo).Success)
                    {
                        ChooseID = tipinfo.Split('.')[1];
                    }

                    if (!string.IsNullOrEmpty(tipinfo))
                    {
                        if (tipinfo.Contains("Station"))
                        {
                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_s,m_runs,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_station where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                        tipinfo = string.Format("数据时间:{0}\n{1}\n变电容量：{2}   运行容量：{3:F2}   {4:F2}%\n电压越限数:{5}   无功越限数:{6}   闭锁数:{7}   控制数:{8}",
                                            dt.Rows[0]["m_time"],
                                            dt.Rows[0]["m_name"], dt.Rows[0]["m_s"], dt.Rows[0]["m_runs"], Convert.ToDouble(dt.Rows[0]["m_runs"]) / Convert.ToDouble(dt.Rows[0]["m_s"]) * 100,
                                            dt.Rows[0]["m_volnunm"], dt.Rows[0]["m_cosnum"], dt.Rows[0]["m_locknum"], dt.Rows[0]["m_ctrlsta"]);
                                }
                            }
                        }

                        else if (tipinfo.Contains("Line"))
                        {

                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_pf,m_qf,m_pt,m_qt from avc_line where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                    {
                                        tipinfo = string.Format("数据时间：{0}\n{1}\n首端有功：{2}  首端无功：{3}\n末端有功：{4}  末端无功：{5}",
                                            dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_pf"], dt.Rows[0]["m_qf"], dt.Rows[0]["m_pt"], dt.Rows[0]["m_qt"]);
                                    }
                                }
                            }

                        }

                        else if (tipinfo.Contains("Switch"))
                        {
                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_runsta from avc_breaker where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                    {
                                        tipinfo = string.Format("数据时间：{0}\n{1}\n运行状态：{2}",
                                            dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_runsta"].ToString() == "1" ? "合上" : "断开");
                                    }
                                }
                            }
                        }

                        else if (tipinfo.Contains("Tfm1") || tipinfo.Contains("Tfm2"))
                        {
                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_s,m_p,m_q,m_cos,m_tap from avc_trans where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                    {
                                        tipinfo = string.Format("数据时间：{0}\n{1}\n容量：{2}\n有功：{3}  无功：{4}  功率：{5}  档位：{6}",
                                            dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_s"], dt.Rows[0]["m_p"], dt.Rows[0]["m_q"], dt.Rows[0]["m_cos"], dt.Rows[0]["m_tap"]);
                                    }
                                }
                            }
                        }

                        else if (tipinfo.Contains("Bus"))
                        {
                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_vol from avc_bus where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                    {
                                        tipinfo = string.Format("数据时间：{0}\n{1}\n当前电压：{2}kV",
                                            dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_vol"]);
                                    }
                                }
                            }
                        }
                        else if (tipinfo.Contains("Load"))
                        {
                            if (ChooseID != "null")
                            {
                                var dt = odb.GetDt(string.Format("select m_time,m_name,m_p,m_q from avc_load where m_id={0}", ChooseID));
                                if (dt != null)
                                {
                                    if (dt.Rows.Count > 0)
                                    {
                                        tipinfo = string.Format("数据时间：{0}\n{1}\n有功：{2}  无功：{3}",
                                            dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_p"], dt.Rows[0]["m_q"]);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            else 
            {
                if (_capturem3d != null)
                {
                    tipinfo = _capturem3d.GetValue(CObjectPosition.TagProperty).ToString();

                    if (!string.IsNullOrEmpty(tipinfo) && regex2.Match(tipinfo).Success)
                    {
                        string ChooseID = tipinfo.Split('.')[1];

                        if (tipinfo.Contains("BarStation"))
                        {
                            var dt = odb.GetDt(string.Format("select m_time,m_name,m_s,m_runs from avc_station where m_id={0}", ChooseID));
                            if (dt != null)
                            {
                                if (dt.Rows.Count > 0)
                                    tipinfo = string.Format("数据时间:{0}\n{1}\n变电容量：{2}   运行容量：{3:F2}   {4:F2}%",
                                        dt.Rows[0]["m_time"],
                                        dt.Rows[0]["m_name"], dt.Rows[0]["m_s"], dt.Rows[0]["m_runs"], Convert.ToDouble(dt.Rows[0]["m_runs"]) / Convert.ToDouble(dt.Rows[0]["m_s"]) * 100);
                            }
                        }
                        else if (tipinfo.Contains("BarTfm"))
                        {
                            var dt = odb.GetDt(string.Format("select m_time,m_name,m_s,m_p,m_q,m_cos,m_tap from avc_trans where m_id={0}", ChooseID));
                            if (dt != null)
                            {
                                if (dt.Rows.Count > 0)
                                {
                                    tipinfo = string.Format("数据时间：{0}\n{1}\n容量：{2}\n有功：{3}  无功：{4}  功率：{5}  档位：{6}",
                                        dt.Rows[0]["m_time"], dt.Rows[0]["m_name"], dt.Rows[0]["m_s"], dt.Rows[0]["m_p"], dt.Rows[0]["m_q"], dt.Rows[0]["m_cos"], dt.Rows[0]["m_tap"]);
                                }
                            }
                        }

                        else if (tipinfo.Contains("BarText"))
                        {
                            var dt = odb.GetDt(string.Format("select m_name,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_station where m_id={0}", ChooseID));
                            if (dt != null)
                            {
                                if (dt.Rows.Count > 0)
                                {
                                    (popTipBar.Child as CtrlNumChart).UpdateData(dt.Rows[0]["m_name"].ToString(), Convert.ToInt32(dt.Rows[0]["m_volnunm"]), Convert.ToInt32(dt.Rows[0]["m_cosnum"]),
                                        Convert.ToInt32(dt.Rows[0]["m_locknum"]), Convert.ToInt32(dt.Rows[0]["m_ctrlsta"]));
                                    Point curLocation = e.GetPosition(this);
                                    popTipBar.HorizontalOffset = curLocation.X + 5;
                                    popTipBar.VerticalOffset = curLocation.Y - 50;
                                    popTipBar.IsOpen = true;
                                }
                            }
                        }   
                    }
                }
            }


            _capturem3d = null;
            if (tipinfo != null)
            {
                Point curLocation = e.GetPosition(this);
                popTip.HorizontalOffset = curLocation.X + 5;
                popTip.VerticalOffset = curLocation.Y - 50;

                TextBlock child = popTip.Child as TextBlock;
                if (child != null)
                    child.Text = tipinfo;

                if (BtnCtrlNum.Tag.ToString() != "1")
                    popTip.IsOpen = true;
            }
            else
            {
                popTip.IsOpen = false;
                popTipBar.IsOpen = false;
            }
        }


        private void scene_TipInfo(object sender, TipEventArgs e)
        {
            _capturem3d = e.dobject as Model3D;
        }

        void UpdateElement()
        {
            UpdatePowerFlow();
            UpdateSwitchStatus();
            UpdateCtrlNum();

            if (BtnTfmBar.Tag.ToString() == "1")
                Bar_Tfm();

            if (BtnStationBar.Tag.ToString() == "1")
                Bar_Station();

            if (BtnCtrlNum.Tag.ToString() == "1")
                BarCtrlNum(true);

            
        }
        
        void UpdatePowerFlow()
        {
            m_szSQL = "select m_id,m_vl,m_s,m_pf,m_qf,m_pt,m_qt from avc_line";
            var lddt = odb.GetDt(m_szSQL);
            if (lddt == null)
                return;

            DB_LineList = ConvertHelper<ST_Line>.ConvertToModel(lddt);
            ST_Line rec;

            if (PosLines != null)
            {
                foreach (CObjectPosition pos in PosLines)
                {
                    var ChooseID = pos.ObjectID;
                    if (ChooseID != null)
                    {
                        rec = (from line in DB_LineList where ChooseID == line.m_id select line).FirstOrDefault();
                        if (rec != null)
                        {
                            val = rec.m_pf;
                            if (Math.Abs(rec.m_pf)<0.001)
                                val = -rec.m_pt;


                            if (Math.Abs(rec.m_s) > 0.001)
                                val /= rec.m_s;
                            else
                                continue;

                            if (Math.Abs(val) < 0.001)
                            {
                                val = 0;
                                continue;

                            }
                            else if (val > 0.001)
                            {
                                val = val > 1 ? 1 : val;
                                val = val < 0.6 ? 0.6 : val;
                            }
                            else if (val < -0.001)
                            {
                                val = val < -1 ? -1 : val;
                                val = val > -0.6 ? -0.6 : val;
                            }

                            scene.SetPowerLineFlowStatus(pos.ObjectID, (float)val, 1000);
                        }
                    }
                }
            }

            if (PosLineSegments != null)
            {
                foreach (CObjectPosition pos in PosLineSegments)
                {
                    var ChooseID = pos.ObjectID;
                    if (ChooseID != null)
                    {
                        if (regex3.Match(pos.ObjectID).Success)
                        {
                            ChooseID = ChooseID.Split('=')[2];

                            rec = (from line in DB_LineList where ChooseID == line.m_id select line).FirstOrDefault();
                            if (rec != null)
                            {
                                val = rec.m_pf;
                                if (Math.Abs(rec.m_pf) < 0.001)
                                    val = -rec.m_pt;


                                if (Math.Abs(rec.m_s) > 0.001)
                                    val /= rec.m_s;
                                else
                                    continue;

                                if (Math.Abs(val) < 0.001)
                                {
                                    val = 0;
                                    continue;

                                }
                                else if (val > 0.001)
                                {
                                    val = val > 1 ? 1 : val;
                                    val = val < 0.4 ? 0.4 : val;
                                }
                                else if (val < -0.001)
                                {
                                    val = val < -1 ? -1 : val;
                                    val = val > -0.4 ? -0.4 : val;
                                }

                                scene.SetPowerLineFlowStatus(pos.ObjectID, (float)val, 100);
                            }
                        }

                    }
                    
                }
            }
        }

        void UpdateSwitchStatus()
        {
            m_szSQL = "select m_id,m_name,m_runsta from avc_breaker";
            var lddt = odb.GetDt(m_szSQL);
            if (lddt == null)
                return;

            DB_BreakerList = ConvertHelper<ST_Breaker>.ConvertToModel(lddt);
            ST_Breaker rec;

            if (PosBreakers != null)
            {
                foreach (CObjectPosition brk in PosBreakers)
                {
                    var ChooseID = brk.ObjectID;
                    if (ChooseID != null)
                    {
                        rec = (from breaker in DB_BreakerList where ChooseID == breaker.m_id select breaker).FirstOrDefault();
                        if(rec != null)
                            scene.SetElementProperty(brk.ObjectID, "ObjectStatus", rec.m_runsta.ToString());
                    }
                }
            }

            if (PosDisconnectors != null)
            {
                foreach (CObjectPosition dis in PosDisconnectors)
                {
                    var ChooseID = dis.ObjectID;
                    if (ChooseID != null)
                    {
                        rec = (from disbreaker in DB_BreakerList where ChooseID == disbreaker.m_id select disbreaker).FirstOrDefault();
                        if (rec != null)
                            scene.SetElementProperty(dis.ObjectID, "ObjectStatus", rec.m_runsta.ToString());
                    }
                }
            }

            if (PosDollyBreakers != null)
            {
                foreach (CObjectPosition dol in PosDollyBreakers)
                {

                    //scene.SetElementProperty(dol.ObjectID, "ObjectStatus", "3");

                    var ChooseID = dol.ObjectID;
                    if (ChooseID != null)
                    {
                        rec = (from dolbreaker in DB_BreakerList where ChooseID == dolbreaker.m_id select dolbreaker).FirstOrDefault();
                        if (rec != null)
                            scene.SetElementProperty(dol.ObjectID, "ObjectStatus", (rec.m_runsta+1).ToString());
                    }
                }
            }
        }

        private void UserControl_IsHitTestVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            popTip.IsOpen = false;
            scene.Dispose();
            GC.Collect();
        }

        private void TfmBar_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            BtnCtrlNum.Tag = "0";
            BtnStationBar.Tag = "0";
            //BtnTfmBar.Tag = "0";

            Button btn = sender as Button;
            if (btn.Tag.ToString() == "0")
            {
                Bar_Tfm();
                btn.Tag = "1";
            }
            else
            {
                if (scene.Model3DGroup != null)
                    scene.Model3DGroup.Children.Clear();

                if (Math.Abs(scene.VRCamera - 90.0) > 0.1)
                    scene.VRCamera = 90;

                btn.Tag = "0";
            } 
        }

        void Bar_Station()
        {
            if (PosStations != null && PosStations.Count>0)
            {
                m_szSQL = "select m_id,m_s,m_runs from avc_station order by m_id";
                var lddt = odb.GetDt(m_szSQL);
                if (lddt == null)
                    return;

                DB_StationList = ConvertHelper<ST_Substation>.ConvertToModel(lddt);
                ST_Substation rst;

                Model3DGroup m3dg = new Model3DGroup();
                Color[] colorG = { Colors.Green, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                Color[] colorR = { Colors.Red, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                EntitrySegment segmentR = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorR, 1, 1);
                EntitrySegment segmentG = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorG, 1, 1);

                if (scene.Model3DGroup != null)
                    scene.Model3DGroup.Children.Clear();

                foreach (CObjectPosition svgstation in PosStations)
                {
                    rst = (from station in DB_StationList where svgstation.ObjectID == station.m_id select station).FirstOrDefault();

                    if (rst != null)
                    {
                        double dValue=1;
                        if (Math.Abs(rst.m_s)>0.01)
                            dValue = rst.m_runs/rst.m_s;
                        double[] vals = { dValue, 1 - dValue };

                        Model3DGroup mdgrp=null;
                        if (dValue > 0.8)
                        {
                            mdgrp = segmentR.BuildSegment();
                            segmentR.SetModelValue(mdgrp, vals);
                        }
                        else
                        {
                            mdgrp = segmentG.BuildSegment();
                            segmentG.SetModelValue(mdgrp, vals);
                        }

                        foreach (Model3D m3d in mdgrp.Children)
                            m3d.SetValue(CObjectPosition.TagProperty, "BarStation."+svgstation.ObjectID);

                        
                        Transform3DGroup t3dgrp = new Transform3DGroup();
                        t3dgrp.Children.Add(new ScaleTransform3D(1.5, 0.7, 1.5));
                        t3dgrp.Children.Add(new TranslateTransform3D(svgstation.ObjectPosition.X + svgstation.ObjectPosition.Width / 2, 0, svgstation.ObjectPosition.Y + svgstation.ObjectPosition.Height / 2));
                        mdgrp.Transform = t3dgrp;
                        m3dg.Children.Add(mdgrp);
                    }
                }

                scene.Model3DGroup = m3dg;
                scene.VRCamera = 45;
                
            }
        }

        void Bar_Tfm()
        {
            if (PosTfms != null && PosTfms.Count>0)
            {
                m_szSQL = "select m_id,m_station,m_s,m_p,m_cos from avc_trans order by m_id";
                var lddt = odb.GetDt(m_szSQL);
                if (lddt == null)
                    return;

                DB_TfmList = ConvertHelper<ST_Tfm>.ConvertToModel(lddt);
                ST_Tfm rst;

                Model3DGroup m3dg = new Model3DGroup();
                Color[] colorG = { Colors.Green, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                Color[] colorR = { Colors.Red, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                EntitrySegment segmentR = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorR, 1, 1);
                EntitrySegment segmentG = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorG, 1, 1);

                if (scene.Model3DGroup != null)
                    scene.Model3DGroup.Children.Clear();

                foreach (CObjectPosition tfm in PosTfms)
                {
                    rst = (from trans in DB_TfmList where tfm.ObjectID == trans.m_id select trans).FirstOrDefault();

                    if (rst != null)
                    {
                        double dValue = 1;
                        if (Math.Abs(rst.m_s)>0.01)
                            dValue = rst.m_p / rst.m_s;
                        double[] vals = { dValue, 1 - dValue };

                        //double[] vals = { rst.m_cos, 1 - rst.m_cos };

                        Model3DGroup mdgrp=null;
                        if (dValue > 0.8)
                        {
                            
                            mdgrp = segmentR.BuildSegment();
                            segmentR.SetModelValue(mdgrp, vals);
                        }
                        else
                        {
                            mdgrp = segmentG.BuildSegment();
                            segmentG.SetModelValue(mdgrp, vals);
                        }

                        foreach (Model3D m3d in mdgrp.Children)
                            m3d.SetValue(CObjectPosition.TagProperty, "BarTfm." + tfm.ObjectID);

                        Transform3DGroup t3dgrp = new Transform3DGroup();
                        
                        t3dgrp.Children.Add(new ScaleTransform3D(1.5, 0.5, 1.5));
                        t3dgrp.Children.Add(new TranslateTransform3D(tfm.ObjectPosition.X + tfm.ObjectPosition.Width / 2, 0, tfm.ObjectPosition.Y + tfm.ObjectPosition.Height / 2));
                        mdgrp.Transform = t3dgrp;
                        m3dg.Children.Add(mdgrp);
                    }
                }
                scene.Model3DGroup = m3dg;
                scene.VRCamera = 45;
            }

            else if (PosStations != null && PosStations.Count>0)
            {
                m_szSQL = "select t.m_id,t.m_station,t.m_s,t.m_p,t.m_cos from avc_station s, avc_trans t where s.m_id=t.m_station order by t.m_id";
                DataTable dt = odb.GetDt(m_szSQL);
                if (dt == null && dt.Rows.Count > 0)
                    return;

                Model3DGroup m3dg = new Model3DGroup();
                Color[] colorG = { Colors.Green, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                Color[] colorR = { Colors.Red, Color.FromArgb(0x77, 0xFF, 0xFF, 0xFF) };
                EntitrySegment segmentR = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorR, 1, 1);
                EntitrySegment segmentG = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, colorG, 1, 1);

                ST_Tfm rst=new ST_Tfm();
                if (scene.Model3DGroup != null)
                    scene.Model3DGroup.Children.Clear();

                foreach (CObjectPosition pos in PosStations)
                {
                    DataRow[] dr = dt.Select(string.Format("m_station={0}", pos.ObjectID));
                    if (dr.Length == 0)
                        continue;


                    for (int i = 0; i < dr.Length; i++ )
                    {
                        rst.m_id = dr[i]["m_id"].ToString();
                        rst.m_s = (float)Convert.ToDouble(dr[i]["m_s"].ToString());
                        rst.m_p = (float)Convert.ToDouble(dr[i]["m_p"].ToString());
                        rst.m_cos = (float)Convert.ToDouble(dr[i]["m_cos"].ToString());

                        double dValue = 1;
                        if (Math.Abs(rst.m_s)>0.01)
                            dValue = rst.m_p / rst.m_s;
                        double[] vals = { dValue, 1 - dValue };


                        Model3DGroup mdgrp=null;
                        if (dValue > 0.8)
                        {
                            
                            mdgrp = segmentR.BuildSegment();
                            segmentR.SetModelValue(mdgrp, vals);
                        }
                        else
                        {
                            mdgrp = segmentG.BuildSegment();
                            segmentG.SetModelValue(mdgrp, vals);
                        }


                        foreach (Model3D m3d in mdgrp.Children)
                            m3d.SetValue(CObjectPosition.TagProperty, "BarTfm." + rst.m_id);

                        Transform3DGroup t3dgrp = new Transform3DGroup();
                        t3dgrp.Children.Add(new ScaleTransform3D(1, 0.5, 1));
                        if (dr.Length == 1)
                            t3dgrp.Children.Add(new TranslateTransform3D(pos.ObjectPosition.X + pos.ObjectPosition.Width / 2, 0, pos.ObjectPosition.Y + pos.ObjectPosition.Height / 2));
                        else
                            t3dgrp.Children.Add(new TranslateTransform3D(pos.ObjectPosition.X + (pos.ObjectPosition.Width / (dr.Length + 1)) * (i + 1), 0, pos.ObjectPosition.Y + pos.ObjectPosition.Height / 2));
                        mdgrp.Transform = t3dgrp;
                        m3dg.Children.Add(mdgrp);
                    }
                }
                scene.Model3DGroup = m3dg;
                scene.VRCamera = 45;
            }
        }

        private void Normal_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            if (scene.Model3DGroup != null)
                scene.Model3DGroup.Children.Clear();

            if(Math.Abs(scene.VRCamera-90.0)>0.1)
                scene.VRCamera = 90;

            if(Math.Abs(scene.HRCamera)>0.1)
                scene.HRCamera = 0;

            SampleTip.Visibility = Visibility.Hidden;
            contour.canv.Visibility = Visibility.Hidden;

            BtnTfmBar.Tag = "0";
            BtnStationBar.Tag = "0";
            BtnCtrlNum.Tag = "0";
        }

        //bool Contour_Line()
        //{
        //    //var color = MediaHelper.getColorBetween(((double)num - 60) / 40, Colors.Yellow, Colors.Red);
            
        //    if (PosLines != null && PosLines.Count>0)
        //    {
        //        var color = new Color();
        //        foreach (CObjectPosition pos in PosLines)
        //        {
        //            color = Color.FromArgb(0xff, 0, 255, 100);//MediaHelper.getColorBetween(((double)num - 60) / 40, Colors.Yellow, Colors.Red);
        //            scene.SetElementProperty(pos.ObjectID, "GradientColor", color);
        //            scene.SetElementProperty(pos.ObjectID, "AnimationStatus", ANIMATIONSTATUS.SHINE);
        //        }
        //        return true;
        //    }
        //    return false;
        //}

        private void StationBar_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            BtnCtrlNum.Tag = "0";
            //BtnStationBar.Tag = "0";
            BtnTfmBar.Tag = "0";

            Button btn = sender as Button;
            if (btn.Tag.ToString() == "0")
            {
                Bar_Station();
                btn.Tag = "1";
            }
            else
            {
                if (scene.Model3DGroup != null)
                {
                    scene.Model3DGroup.Children.Clear();
                    scene.VRCamera = 90;
                }
                btn.Tag = "0";
            } 
            
        }

        void BarCtrlNum(bool bUpdate = false)
        {
            DataTable dt = odb.GetDt("select m_id,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_station");
            if (dt == null && dt.Rows.Count > 0)
                return;

            if (PosStations != null && PosStations.Count > 0)
            {
                if (scene.Model3DGroup != null)
                    scene.Model3DGroup.Children.Clear();

                Model3DGroup m3dg = new Model3DGroup();
                Color col = Colors.Gray;
                double[] vals = { 0.25, 0.25, 0.25, 0.25 };
                foreach (CObjectPosition pos in PosStations)
                {
                    DataRow[] dr = dt.Select(string.Format("m_id={0}", pos.ObjectID));
                    if (dr.Length == 0)
                        continue;

                    Color[] color = { Colors.Red, Colors.Blue, Colors.Magenta, Colors.Cyan };
                    if (dr[0]["m_volnunm"].ToString() == "0") color[0] = col;
                    if (dr[0]["m_cosnum"].ToString() == "0") color[1] = col;
                    if (dr[0]["m_locknum"].ToString() == "0") color[2] = col;
                    if (dr[0]["m_ctrlsta"].ToString() == "0") color[3] = col;

                    EntitrySegment segment = new EntitrySegment(EntitrySegment.EntitryType.CylinderType, color, 1);
                    Model3DGroup mdgrp = segment.BuildSegment();
                    segment.SetModelValue(mdgrp, vals);

                    foreach (Model3D m3d in mdgrp.Children)
                        m3d.SetValue(CObjectPosition.TagProperty, "BarText." + pos.ObjectID);

                    Transform3DGroup t3dgrp = new Transform3DGroup();
                    t3dgrp.Children.Add(new ScaleTransform3D(1.5, 0.8, 1.5));
                    t3dgrp.Children.Add(new TranslateTransform3D(pos.ObjectPosition.X + pos.ObjectPosition.Width / 2, 0, pos.ObjectPosition.Y + pos.ObjectPosition.Height / 2));
                    mdgrp.Transform = t3dgrp;

                    m3dg.Children.Add(mdgrp);
                }
                scene.Model3DGroup = m3dg;
                scene.VRCamera = 45;

                
            }
        }

        //void BarCtrlNum(bool bUpdate = false)
        //{
        //    DataTable dt = odb.GetDt("select m_id,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_station");
        //    if (dt == null && dt.Rows.Count > 0)
        //        return;

        //    if (PosStations != null && PosStations.Count > 0)
        //    {
        //        if (scene.Model3DGroup != null)
        //            scene.Model3DGroup.Children.Clear();

        //        Model3DGroup m3dg = new Model3DGroup();
        //        Color col = Colors.Gray;
        //        double[] vals = { 0.25, 0.25, 0.25, 0.25 };
        //        foreach (CObjectPosition pos in PosStations)
        //        {
        //            DataRow[] dr = dt.Select(string.Format("m_id={0}", pos.ObjectID));
        //            if (dr.Length == 0)
        //                continue;

        //            SphereVisual3D a = new SphereVisual3D() { Radius = 0.1 };
        //            a.Model.SetValue(CObjectPosition.TagProperty, "BarText." + pos.ObjectID);


        //            Transform3DGroup t3dgrp = new Transform3DGroup();
        //            t3dgrp.Children.Add(new ScaleTransform3D(1, 1, 1));
        //            t3dgrp.Children.Add(new TranslateTransform3D(pos.ObjectPosition.X + pos.ObjectPosition.Width / 2, 0, pos.ObjectPosition.Y + pos.ObjectPosition.Height / 2));
        //            a.Model.Transform = t3dgrp;

        //            m3dg.Children.Add(a.Model);
        //        }
        //        scene.Model3DGroup = m3dg;
        //        scene.VRCamera = 45;
        //    }
        //}

        

        void UpdateCtrlNum()
        {
            DataTable dt = odb.GetDt(string.Format(@"select * from (select m_id,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_station 
union select m_id,m_volnunm,m_cosnum,m_locknum,m_ctrlsta from avc_syszone) where m_id={0}", GlobalInfo.selStationID));
            if (dt != null && dt.Rows.Count > 0)
            {
                volnum.Text = "电压越限数: " + dt.Rows[0]["m_volnunm"].ToString();
                cosnum.Text = "无功越限数: " + dt.Rows[0]["m_cosnum"].ToString();
                locknum.Text = "闭  锁  数: " + dt.Rows[0]["m_locknum"].ToString();
                ctrlnum.Text = "控  制  数: " + dt.Rows[0]["m_ctrlsta"].ToString();
            }
        }

        private void CtrlNumText_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            //BtnCtrlNum.Tag = "0";
            BtnStationBar.Tag = "0";
            BtnTfmBar.Tag = "0";

            Button btn = sender as Button;
            if (btn.Tag.ToString() == "0")
            {
                BarCtrlNum();
                btn.Tag = "1";
            }
            else
            {
                if (scene.Model3DGroup != null)
                {
                    scene.Model3DGroup.Children.Clear();
                    scene.VRCamera = 90;
                }
                btn.Tag = "0";
            }
        }

        
    }
}

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
using VoltageQ.CommonFunc;

namespace VoltageQ.Controls
{
    /// <summary>
    /// HisNinePointControl.xaml 的交互逻辑
    /// </summary>
    public partial class HisNinePointControl : UserControl
    {
        class ItemInfo
        {
            double x, y;
            //public double X { get { return x; } set { x = value; Canvas.SetLeft(circle, x); Canvas.SetLeft(lab, x); } }
            //public double Y { get { return y; } set { y = value; Canvas.SetTop(circle, y); Canvas.SetTop(lab, y + 20); } }

            public double X 
            {
                get { return x; } 
                set 
                {
                    x = value; Canvas.SetLeft(circle, x); //Canvas.SetLeft(lab, x);
                } 
            }
            public double Y 
            {
                get { return y; } 
                set 
                {
                    y = value; Canvas.SetTop(circle, y); //Canvas.SetTop(lab, y+20);
                } 
            }

            SolidColorBrush purecolor;
            public SolidColorBrush PureColor //纯色
            {
                get { return purecolor; }
                set
                {
                    purecolor = value;
                    circle.Fill = purecolor;
                }
            }

            RadialGradientBrush gradientcolor;
            public RadialGradientBrush GradientColor //渐变色
            {
                get { return gradientcolor; }
                set
                {
                    gradientcolor = value;
                    circle.Fill = gradientcolor;
                }
            }

            string content;
            //public string Content { get { return content; } set { content = value; circle.ToolTip = content; lab.Content = content; } }
            public string Content { get { return content; } set { content = value; circle.ToolTip = content;  } }

            int pos;
            public int Pos { get { return pos; } set { pos = value; circle.Tag = pos; } }

            //bool showlab;
            //public bool ShowLab
            //{
            //    get { return showlab; }
            //    set
            //    {
            //        showlab = value;
            //        if (showlab == true)
            //        {
            //            lab.Visibility = Visibility.Visible;
            //            lab.IsEnabled = false;
            //        }
            //        else
            //            lab.Visibility = Visibility.Hidden;
            //    }
            //}

            //public void SetLabPos(double x, double y)
            //{
            //    Canvas.SetLeft(lab, x);
            //    Canvas.SetTop(lab, y ); 
            //}

            public Ellipse circle;
            //public Label lab;
            public ItemInfo(double Diameter)
            {
                circle = new Ellipse();
                circle.Fill = Brushes.Red;
                circle.Width = Diameter;
                circle.Height = Diameter;

                //lab = new Label();
                //lab.IsEnabled = false;
                //lab.Visibility = Visibility.Hidden;
            }
        }
        List<ItemInfo> data = new List<ItemInfo>();

        double m_dTop, m_dLeft, m_dBottom, m_dRight;
        public double m_dWidth, m_dHeight, m_dAllWidth, m_dAllHeight;//中间方形的长宽 和 整个的长宽
        double m_dDiameter = 10.0;
        OracleDataBase odb = new OracleDataBase();

        RadialGradientBrush greenRadial = new RadialGradientBrush();
        RadialGradientBrush redRadial = new RadialGradientBrush();

        public HisNinePointControl()
        {
            InitializeComponent();
            greenRadial.GradientOrigin = new Point(0.7, 0.3);
            greenRadial.RadiusX = 1;
            greenRadial.RadiusY = 1;
            GradientStop stop1 = new GradientStop();
            stop1.Color = Colors.White;
            stop1.Offset = 0;
            greenRadial.GradientStops.Add(stop1);
            GradientStop stop2 = new GradientStop();
            stop2.Color = Colors.Green;
            stop2.Offset = 1;
            greenRadial.GradientStops.Add(stop2);

            redRadial.GradientOrigin = new Point(0.7, 0.3);
            redRadial.RadiusX = 1;
            redRadial.RadiusY = 1;
            GradientStop stop3 = new GradientStop();
            stop3.Color = Colors.White;
            stop3.Offset = 0;
            redRadial.GradientStops.Add(stop3);
            GradientStop stop4 = new GradientStop();
            stop4.Color = Colors.Red;
            stop4.Offset = 1;
            redRadial.GradientStops.Add(stop4);

            for (int i = 0; i < 96; i++)
            {
                ItemInfo item = new ItemInfo(m_dDiameter);
                item.Content = i.ToString();
                item.Pos = i;
                //item.circle.MouseRightButtonDown += new MouseButtonEventHandler(circle_MouseRightButtonDown);
                item.circle.MouseLeftButtonDown += new MouseButtonEventHandler(circle_MouseLeftButtonDown);
                data.Add(item);
                canvas.Children.Add(item.circle);
                //canvas.Children.Add(item.lab);
            }
        }

       

        private void canvas_Loaded(object sender, RoutedEventArgs e)
        {
            m_dAllWidth = canvas.ActualWidth;
            m_dAllHeight = canvas.ActualHeight;
            m_dTop = m_dAllHeight / 7;
            m_dLeft = m_dAllWidth / 7;
            m_dBottom = m_dAllHeight - m_dTop;
            m_dRight = m_dAllWidth - m_dLeft;
            m_dWidth = m_dAllWidth - 2 * m_dLeft;
            m_dHeight = m_dAllHeight - 2 * m_dTop;

            Random raX = new Random(1);
            Random raY = new Random(3);

            ItemInfo item;

            double xTemp, yTemp;
            for (int i = 0; i < data.Count; i++)
            {
                item = data.ElementAt(i);

                xTemp = raX.Next((int)m_dAllWidth);
                yTemp = raY.Next((int)m_dAllHeight);

                if (xTemp > m_dAllWidth - m_dDiameter)
                {
                    xTemp = m_dAllWidth - m_dDiameter;
                    //item.SetLabPos(xTemp-20, yTemp);
                    //Canvas.SetLeft(item.lab, xTemp-20);
                }
                else if (xTemp < m_dDiameter)
                {
                    xTemp = m_dDiameter;
                    //Canvas.SetLeft(item.lab, xTemp + 20);
                }

                if (yTemp > m_dAllHeight - m_dDiameter)
                {
                    yTemp = m_dAllHeight - m_dDiameter;
                    //Canvas.SetTop(item.lab, yTemp-20);
                }
                else if (yTemp < m_dDiameter)
                {
                    yTemp = m_dDiameter;
                    //Canvas.SetTop(item.lab, yTemp + 20);
                }

                item.X = xTemp;//raX.NextDouble() * m_dAllWidth;
                item.Y = yTemp;//raY.NextDouble() * m_dAllHeight;
                

                if (item.X + 5 > m_dRight || item.X + 5 < m_dLeft || item.Y + 5 < m_dTop || item.Y + 5 > m_dBottom)
                {
                    //item.PureColor = Brushes.Red; 
                    item.GradientColor = redRadial;
                }
                else
                {
                    //item.PureColor = Brushes.Green;
                    item.GradientColor = greenRadial;//Brushes.Green;
                }
            }
        }

        bool bShowBig = false;
        void circle_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        //void circle_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            Ellipse circle = sender as Ellipse;
            int nIndex = Convert.ToInt32(circle.Tag);
            ItemInfo item;

            if (bShowBig == false)
            {
                for (int i = 0; i < data.Count; i++)
                {
                    if (i >= nIndex - 5 && i <= nIndex + 5)
                    {
                        data.ElementAt(i).circle.Width = 20;
                        data.ElementAt(i).circle.Height = 20;

                        //if()
                        //data.ElementAt(i).ShowLab = true;
                        pl.Points.Add(new Point(data.ElementAt(i).X + 10, data.ElementAt(i).Y + 10));
                    }
                    else
                    {
                        data.ElementAt(i).circle.Opacity = 0.3;
                        //data.ElementAt(i).ShowLab = false;
                    }
                }
                bShowBig = true;
            }
            else
            {
                bShowBig = false;
                for (int i = 0; i < data.Count; i++)
                {
                    data.ElementAt(i).circle.Width = m_dDiameter;
                    data.ElementAt(i).circle.Height = m_dDiameter;
                    data.ElementAt(i).circle.Opacity = 1;
                    //data.ElementAt(i).ShowLab = false;
                }
                pl.Points.Clear();
            }
        }

        private void canvas_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            if (e.NewSize.Width == 0 || e.PreviousSize.Width == 0)
                return;

            m_dAllWidth = canvas.ActualWidth;
            m_dAllHeight = canvas.ActualHeight;
            m_dTop = m_dAllHeight / 7;
            m_dLeft = m_dAllWidth / 7;
            m_dBottom = m_dAllHeight - m_dTop;
            m_dRight = m_dAllWidth - m_dLeft;
            m_dWidth = m_dAllWidth - 2 * m_dLeft;
            m_dHeight = m_dAllHeight - 2 * m_dTop;

            topLine.X1 = 0;
            topLine.Y1 = topLine.Y2 = m_dTop;
            topLine.X2 = m_dAllWidth;

            bottomLine.X1 = 0;
            bottomLine.Y1 = bottomLine.Y2 = m_dBottom;
            bottomLine.X2 = m_dAllWidth;

            leftLine.X1 = leftLine.X2 = m_dLeft;
            leftLine.Y1 = 0;
            leftLine.Y2 = m_dAllHeight;

            rightLine.X1 = rightLine.X2 = m_dRight;
            rightLine.Y1 = 0;
            rightLine.Y2 = m_dAllHeight;

            double dChangeWidthRate = e.NewSize.Width / e.PreviousSize.Width;
            double dChangeHeightRate = e.NewSize.Height / e.PreviousSize.Height;
            for (int i = 0; i < data.Count; i++)
            {
                data.ElementAt(i).X *= dChangeWidthRate;
                data.ElementAt(i).Y *= dChangeHeightRate;
            }
        }
    }
}

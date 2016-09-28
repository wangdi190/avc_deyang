using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Input;
using VoltageQ.CommonFunc;
using System.Data;

namespace VoltageQ.ViewModels
{
    class RealRunControlModel:ViewModelBase
    {
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();


        public ICommand Control_Loaded
        {
            get
            {
                return new RelayCommand(param =>
                {
                    //1系统，2区域，3厂站，4电压等级
                    string m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=2 order by r_name";
                    data = odb.GetDt(m_szSQL);
                    if (data != null)
                        Tree_Zone = data.DefaultView;

                    m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=3  order by r_name";
                    data = odb.GetDt(m_szSQL);
                    if (data != null)
                        Tree_Station = data.DefaultView;

                    m_szSQL = "select r_type,r_name from avc_realsystem where r_isreal=1 and r_type=4  order by r_name";
                    data = odb.GetDt(m_szSQL);
                    if (data != null)
                        Tree_Voltage = data.DefaultView;
                });
            }
        }

        private DataView _tree_zone;
        public DataView Tree_Zone
        {
            get { return _tree_zone; }
            set
            {
                _tree_zone = value;
                 OnPropertyChanged("Tree_Zone");
            }
        }

        private DataView _tree_station;
        public DataView Tree_Station
        {
            get { return _tree_station; }
            set
            {
                _tree_station = value;
                OnPropertyChanged("Tree_Station");
            }
        }

        private DataView _tree_voltage;
        public DataView Tree_Voltage
        {
            get { return _tree_voltage; }
            set
            {
                _tree_voltage = value;
                OnPropertyChanged("Tree_Voltage");
            }
        }
    }
}

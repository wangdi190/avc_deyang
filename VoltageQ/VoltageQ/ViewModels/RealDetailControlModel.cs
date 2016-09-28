using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Input;
using VoltageQ.CommonFunc;
using System.Data;

namespace VoltageQ.ViewModels
{
    class RealDetailControlModel:ViewModelBase
    {
        private DataTable data;
        OracleDataBase odb = new OracleDataBase();
        string m_szSQL;

        public ICommand Control_Loaded
        {
            get
            {
                return new RelayCommand(param =>
                {
                    UpdateData();
                });
            }
        }

        public ICommand Control_UnLoaded
        {
            get
            {
                return new RelayCommand(param =>
                {

                });
            }
        }

        public void UpdateData()
        {
            m_szSQL = "select r_time,r_name from avc_realsystem where r_isreal=1 and r_type=3";
            data = odb.GetDt(m_szSQL);
            if (data != null)
                DataDetail = data.DefaultView;
        }

        private DataView dataDetail;
        public DataView DataDetail
        {
            get { return dataDetail; }
            set
            {
                dataDetail = value;
                OnPropertyChanged("DataDetail");
            }
        }


    }
}

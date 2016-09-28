using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.OracleClient;

namespace VoltageQ.CommonFunc
{
    /// <summary>
    /// Oracle数据库通用操作类
    /// </summary>
    public class OracleDataBase
    {
        #region 初始化常用变量

        //private static string OracleConn = "Provider=OraOLEDB.Oracle;Data Source=orcl;User Id=power;Password=sa;";
        //private static string OracleConn = "Data Source=orcl;User Id=power;Password=sa;Integrated Security=no;";
        //private static string OracleConn = "server=127.0.0.1;uid=power;pwd=sa;data source=orcl";

  //      "ORCL =
  //(DESCRIPTION =
  //  (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))
  //  (CONNECT_DATA =
  //    (SERVER = DEDICATED)
  //    (SERVICE_NAME = orcl)
  //  )
  //)"
        //private static string OracleConn = "Data Source=ORCL;User Id=dywg;Password=sa;";//= System.Configuration.ConfigurationSettings.AppSettings["ConnectionStrings"];
//        private static string OracleConn = @"Data Source=(DESCRIPTION =
//    (ADDRESS = (PROTOCOL = TCP)(HOST = 192.168.1.155)(PORT = 1521))
//    (CONNECT_DATA =
//      (SERVER = DEDICATED)
//      (SERVICE_NAME = orcl)
//    )
//  );User Id=dywg;Password=sa;";

        
        private static string OracleConn = System.Configuration.ConfigurationSettings.AppSettings["ConnectionString"];

        //       172.16.1.210/ORCL //192.168.253.4  192.168.1.155
        private OracleConnection con;     //创建SQL连接        
        private OracleDataAdapter sda;    //创建SQL数据适配器
        private OracleDataReader sdr;     //创建SQL数据阅读器
        private OracleParameter param;    //创建SQL参数       
        private DataTable dt;             //创建数据表
        #endregion

        #region 创建并打开数据库连接
        /// <summary>
        /// 创建并打开数据库连接
        /// </summary>
        public bool OpenCon()
        {
            con = new OracleConnection(OracleConn);
            try
            {
                con.Open();
                //Log.Record.execFileRecordInfo("打开数据库成功。");
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("打开Oracle数据库异常：" + ex.Message);
                
                return false;
            }

            return true;
        }
        #endregion

        #region 关闭已打开的连接
        /// <summary>
        /// 关闭已打开的连接
        /// </summary>
        private void CloseCon()
        {
            if (con != null && con.State != ConnectionState.Closed)
            {
                try
                {
                    con.Close();
                    con.Dispose();
                    //Log.Record.execFileRecordInfo("关闭数据库成功。");
                }
                catch (Exception ex)
                {
                    //Log.Record.execFileRecord("关闭Oracle数据库异常：" + ex.Message);
                }
            }
        }
        #endregion

        #region 返回数据集
        /// <summary>
        /// 返回数据集
        /// </summary>
        /// <param name="sqlstring">SQL语句</param>
        /// <returns>数据集</returns>
        public DataTable GetDt(string sqlString)
        {
            if (!OpenCon())
            {
                return null;
            }

            try
            {
                sda = new OracleDataAdapter(sqlString, con);
                dt = new DataTable();
                sda.Fill(dt);
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("GetDt", ex.Message);
            }
            finally
            {
                if (sdr != null)
                {
                    sdr.Dispose();
                    sdr = null;
                }
                CloseCon();
            }
            return dt;
            
        }
        #endregion

        #region 获取数据视图
        /// <summary>
        /// 获取数据视图
        /// </summary>
        /// <param name="sqlstring">SQL语句</param>
        /// <returns>数据视图</returns>
        public DataView GetDv(string sqlString)
        {
            DataTable dt = GetDt(sqlString);
            if (dt == null)
            {
                return null;
            }
            else
            {
                return dt.DefaultView;
            }
        }
        #endregion

        #region 获取阅读器
        /// <summary>
        /// 获取阅读器
        /// </summary>
        /// <param name="sqlString">SQL语句</param>
        /// <returns>阅读器,null 表示失败，其他表示成功</returns>
        public OracleDataReader GetDataReader(string sqlString)
        {
            if (!OpenCon())
            {
                return null;
            }

            OracleCommand cmd = null;
            try
            {
                if (sdr != null)
                {
                    sdr.Dispose();
                    sdr = null;
                }

                cmd = new OracleCommand(sqlString, con);
                sdr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("GetDataReader", ex.Message);
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                CloseCon();
            }
            
            return sdr;
        }
        #endregion

        #region 执行SQL语句
        /// <summary>
        /// 执行SQL语句
        /// </summary>
        /// <param name="sqlString">SQL语句</param>
        /// <returns>-1 表示失败，其他表示正常</returns>
        public int ExecSql(string sqlString)
        {
            int flag = -1;

            if (!OpenCon())
            {
                return flag;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = new OracleCommand(sqlString, con);
                flag = (int)cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("ExecSql", ex.Message);
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                CloseCon();
            }
            return flag;
        }
        #endregion

        #region 执行带参SQL语句
        /// <summary>
        /// 执行带参SQL语句
        /// </summary>
        /// <param name="sqlString">SQL带参语句</param>
        /// <returns>执行SQL语句返回值</returns>
        public int ExecParmSql(string sqlString, OracleParameter[] parms)
        {
            int iReturnValue = -1;
            if (!OpenCon())
            {
                return iReturnValue;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BuildSqlCommand(sqlString, parms);
                cmd.ExecuteNonQuery();
                iReturnValue = (int)cmd.Parameters["ReturnValue"].Value;
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("ExecParmSql",ex.Message);
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                CloseCon();
            }
            return iReturnValue;
        }
        #endregion

        #region 执行带参SQL语句,返回数据阅读对象
        /// <summary>
        /// 执行带参SQL语句,返回数据阅读对象
        /// </summary>
        /// <param name="sqlString">带参SQL语句</param>
        /// <param name="parms">SQL语句参数</param>
        /// <returns>数据阅读器</returns>
        public OracleDataReader ExecParmSqlReader(string sqlString, OracleParameter[] parms)
        {
            if (!OpenCon())
            {
                return null;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BuildSqlCommand(sqlString, parms);
                sdr = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("ExecParmSqlReader", ex.Message);
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                if (sdr != null)
                {
                    sdr.Dispose();
                    sdr = null;
                }
                CloseCon();
            }
            return sdr;
        }
        #endregion

        #region 执行带参SQL语句
        /// <summary>
        /// 执行带参SQL语句
        /// </summary>
        /// <param name="sqlString">SQL带参语句</param>
        /// <param name="parms">参数</param>
        /// <returns>数据集</returns>
        public DataTable ExecParmSqlDs(string sqlString, OracleParameter[] parms)
        {
            DataTable dt = null;
            if (!OpenCon())
            {
                return dt;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BuildSqlCommand(sqlString, parms);
                sda = new OracleDataAdapter(cmd);
                dt = new DataTable();
                sda.Fill(dt);
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("ExecParmSqlDs", ex.Message);
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                if (sda != null)
                {
                    sda.Dispose();
                    sda = null;
                }
                CloseCon();
            }
            return dt;
        }
        #endregion

        #region 执行存储过程
        /// <summary>
        /// 执行存储过程
        /// </summary>
        /// <param name="procName">存储过程名</param>
        /// <returns>返回值</returns>
        public int ExecProc(string procName)
        {
            int iReturnValue = -1;
            if (!OpenCon())
            {
                return iReturnValue;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BulidProcCommand(procName, null);
                cmd.ExecuteNonQuery();
                iReturnValue = (int)cmd.Parameters["ReturnValue"].Value;
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord(string.Format("执行存储过程[{0}]异常:{1}", procName, ex.Message));
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                CloseCon();
            }

            return iReturnValue;
        }
        #endregion

        #region 执行带参数的存储过程
        /// <summary>
        /// 执行带参数的存储过程
        /// </summary>
        /// <param name="procName">存储过程名</param>
        /// <param name="parms">存储过程参数</param>
        /// <returns>存储过程返回值</returns>
        public int ExecProc(string procName, OracleParameter[] parms)
        {
            int iReturnValue = -1;
            if (!OpenCon())
            {
                return iReturnValue;
            }

            OracleCommand cmd = null;
            try
            {
                cmd = BulidProcCommand(procName, parms);
                cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord(string.Format("执行存储过程[{0}]异常:{1}", procName, ex.Message));
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                CloseCon();
            }
            return iReturnValue;
        }
        #endregion

        #region 执行存储过程
        /// <summary>
        /// 执行存储过程
        /// </summary>
        /// <param name="procName">存储过程名</param>
        /// <param name="dataReader">数据阅读器</param>
        public void ExecProc(string procName, OracleDataReader dataReader)
        {
            if (!OpenCon())
            {
                dataReader = null;
                return;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BulidProcCommand(procName, null);
                dataReader = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord(string.Format("执行存储过程[{0}]异常:{1}", procName, ex.Message));
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                if (dataReader != null)
                {
                    dataReader.Dispose();
                    dataReader = null;
                }
                CloseCon();
            }
        }
        #endregion

        #region 执行存储过程
        /// <summary>
        ///执行存储过程
        /// </summary>
        /// <param name="procName">过程名</param>
        /// <param name="parms">过程参数</param>
        /// <param name="dataReader">阅读器</param>
        public void ExecProc(string procName, OracleParameter[] parms, OracleDataReader dataReader)
        {
            if (!OpenCon())
            {
                dataReader = null;
                return;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = BulidProcCommand(procName, parms);
                dataReader = cmd.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                dataReader = null;
                //Log.Record.execFileRecord(string.Format("执行存储过程[{0}]异常:{1}", procName, ex.Message));
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }
                if (dataReader != null)
                {
                    dataReader.Dispose();
                    dataReader = null;
                }
                CloseCon();
            }
        }
        #endregion

        #region 执行存储过程
        /// <summary>
        /// 执行存储过程
        /// </summary>
        /// <param name="procName">过程名</param>
        /// <param name="parms">过程参数</param>
        /// <returns>返回数据集</returns>
        public DataTable ExecProcDs(string procName, OracleParameter[] parms)
        {
            if (!OpenCon())
            {
                return null;
            }
            OracleCommand cmd = null;
            try
            {
                cmd = new OracleCommand(procName, con);
                cmd.CommandType = CommandType.StoredProcedure;
                if (parms != null)
                {
                    foreach (OracleParameter parameter in parms)
                    {
                        cmd.Parameters.Add(parameter);
                    }
                }
                OracleParameter sqlpar = new OracleParameter("dataset", OracleType.Cursor);
                sqlpar.Direction = System.Data.ParameterDirection.Output;
                cmd.Parameters.Add(sqlpar);

                sda = new OracleDataAdapter(cmd);
                dt = new DataTable();
                sda.Fill(dt);
            }
            catch (Exception ex)
            {
                dt = null;
                //Log.Record.execFileRecord(string.Format("执行存储过程[{0}]异常:{1}", procName, ex.Message));
            }
            finally
            {
                if (cmd != null)
                {
                    cmd.Dispose();
                    cmd = null;
                }

                if (sda != null)
                {
                    sda.Dispose();
                    sda = null;
                }

                CloseCon();
            }

            return dt;
        }
        #endregion

        #region 生成存储过程命令对象
        /// <summary>
        /// 生成存储过程命令对象
        /// </summary>
        /// <param name="procName">存储过程名</param>
        /// <param name="parms">存储过程参数</param>
        /// <returns>命令对象</returns>
        private OracleCommand BulidProcCommand(string procName, OracleParameter[] parms)
        {
            OracleCommand cmd = null;
            try
            {
                cmd = new OracleCommand(procName, con);
                cmd.CommandType = CommandType.StoredProcedure;
                if (parms != null)
                {
                    foreach (OracleParameter parameter in parms)
                    {
                        cmd.Parameters.Add(parameter);
                    }
                }
                cmd.Parameters.Add(new OracleParameter("ReturnValue", OracleType.Int16, 4, ParameterDirection.ReturnValue, false, 0, 0, string.Empty, DataRowVersion.Default, null));
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("BulidProcCommand", ex.Message);
            }

            return cmd;
        }
        #endregion

        #region 生成SQL命令对象
        /// <summary>
        /// 生成SQL命令对象
        /// </summary>
        /// <param name="sqlstr">SQL带参语句</param>
        /// <param name="parms">SQL语句参数</param>
        /// <returns>SQL命令对象</returns>
        public OracleCommand BuildSqlCommand(string sqlstr, OracleParameter[] parms)
        {
            OracleCommand cmd = null;
            try
            {
                cmd = new OracleCommand(sqlstr, con);
                cmd.CommandType = CommandType.Text;
                if (parms != null)
                {
                    foreach (OracleParameter parameter in parms)
                    {
                        cmd.Parameters.Add(parameter);
                    }
                }
                cmd.Parameters.Add(new OracleParameter("ReturnValue", OracleType.Int16, 4, ParameterDirection.ReturnValue, false, 0, 0, string.Empty, DataRowVersion.Default, null));
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("BuildSqlCommand", ex.Message);
            }

            return cmd;
        }

        /// <summary>
        /// 生成SQL命令对象
        /// </summary>
        /// <param name="sqlstr">SQL带参语句</param>
        /// <param name="parms">SQL语句参数</param>
        /// <returns>SQL命令对象</returns>
        public OracleCommand BuildSqlCommand(string sqlstr)
        {
            OracleCommand cmd = null;
            try
            {
                cmd = new OracleCommand(sqlstr, con);
                cmd.CommandType = CommandType.Text;
                cmd.Parameters.Add(new OracleParameter("ReturnValue", OracleType.Int16, 4, ParameterDirection.ReturnValue, false, 0, 0, string.Empty, DataRowVersion.Default, null));
            }
            catch (Exception ex)
            {
                //Log.Record.execFileRecord("BuildSqlCommand", ex.Message);
            }
            return cmd;
        }
        #endregion

        #region 生成过程参数
        /// <summary>
        /// 生成过程参数
        /// </summary>
        /// <param name="proName">过程名</param>
        /// <param name="dbTpye">数据类型</param>
        /// <param name="size">数据大小</param>
        /// <param name="direction">参数方向</param>
        /// <param name="value">参数值</param>
        /// <returns>过程参数</returns>
        private OracleParameter MakeParm(string parmName, OracleType dbTpye, Int32 size, ParameterDirection direction, object value)
        {
            if (size > 0)
            {
                param = new OracleParameter(parmName, dbTpye, size);
            }
            else
            {
                param = new OracleParameter(parmName, dbTpye);
            }
            param.Direction = direction;
            if (!(direction == ParameterDirection.Output && value == null))
            {
                param.Value = value;
            }
            return param;
        }
        #endregion

        #region 生成存储过程输入参数
        /// <summary>
        /// 生成存储过程输入参数
        /// </summary>
        /// <param name="procName">过程名</param>
        /// <param name="dbType">参数类型</param>
        /// <param name="size">参数大小</param>
        /// <param name="value">参数值</param>
        /// <returns>过程参数</returns>
        public OracleParameter MakeInParm(string parmName, OracleType dbType, Int32 size, object value)
        {
            return MakeParm(parmName, dbType, size, ParameterDirection.Input, value);
        }
        #endregion

        #region 生成存储过程输出参数
        /// <summary>
        /// 生成存储过程输出参数
        /// </summary>
        /// <param name="procName">过程名</param>
        /// <param name="dbType">参数类型</param>
        /// <param name="size">参数大小</param>
        /// <param name="value">参数值</param>
        /// <returns>过程参数</returns>
        public OracleParameter MakOutParm(string parmName, OracleType dbType, Int32 size)
        {
            return MakeParm(parmName, dbType, size, ParameterDirection.Output, null);
        }
        #endregion

        #region 测试Oracle连接
        /// <summary>
        /// 测试Oracle连接
        /// </summary>
        /// <returns></returns>
        //public static bool TestOracleConn()
        //{
        //    string strErrMsg = "";
        //    return TestOracleConn(Config.GetOracleConn(), out strErrMsg);
        //}

        /// <summary>
        /// 测试Oracle连接
        /// </summary>
        /// <param name="strOracleConn">测试Oracle连接字符串</param>
        /// <returns></returns>
        public static bool TestOracleConn(string strOracleConn, out string strErrMsg)
        {
            OracleConnection conn = null;
            strErrMsg = "";
            try
            {
                conn = new OracleConnection(strOracleConn);
                conn.Open();
            }
            catch (Exception ex)
            {
                strErrMsg = ex.Message;
                return false;
            }
            finally
            {
                if (conn != null)
                {
                    if (conn.State == ConnectionState.Open)
                    {
                        conn.Close();
                    }

                    conn.Dispose();
                    conn = null;
                }
            }

            return true;
        }
        #endregion
    }
}

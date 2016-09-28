# Microsoft Developer Studio Project File - Name="ParseDataFile" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ParseDataFile - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ParseDataFile.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ParseDataFile.mak" CFG="ParseDataFile - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ParseDataFile - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ParseDataFile - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ParseDataFile - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O2 /I "../include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"D:\bin_avc\ParseDataFile.exe"

!ELSEIF  "$(CFG)" == "ParseDataFile - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /Zp1 /MTd /W3 /Gm /GX /ZI /Od /I "../include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"E:\wangdi\四川电压无功\bin_avc\ParseDataFile.exe" /pdbtype:sept /libpath:"../lib"

!ENDIF 

# Begin Target

# Name "ParseDataFile - Win32 Release"
# Name "ParseDataFile - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CommonFunc.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcBus.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlPloy.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlZone.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRelay.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRunParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRunTimePart.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcShunt.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCShuntEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCStatInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcStation.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCTranEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AvcTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCVolEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCWarnInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCWarnType.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_AVCZoneChange.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_CommonVec.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_PASIsland.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_PASMeasure.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_PASParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_PASRuninfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwBus.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwGen.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwLine.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwLoad.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwShuntSreact.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwStation.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwSwitch.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwTfm.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwTfmTap.cpp
# End Source File
# Begin Source File

SOURCE=.\DB_pwZone.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog_Log.cpp
# End Source File
# Begin Source File

SOURCE=.\IDbInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Parse.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseDataFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseDataFile.rc
# End Source File
# Begin Source File

SOURCE=.\ParseDataFileDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RealDataBase.cpp
# End Source File
# Begin Source File

SOURCE=.\RealSearth.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Utils.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CommonDefine.h
# End Source File
# Begin Source File

SOURCE=.\CommonFunc.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcBus.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlEvent.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlParam.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlPloy.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCCtrlZone.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRelay.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRunParam.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcRunTimePart.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcShunt.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCShuntEvent.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCStatInfo.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcStation.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCTranEvent.h
# End Source File
# Begin Source File

SOURCE=.\DB_AvcTrans.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCVolEvent.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCWarnInfo.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCWarnType.h
# End Source File
# Begin Source File

SOURCE=.\DB_AVCZoneChange.h
# End Source File
# Begin Source File

SOURCE=.\DB_CommonVec.h
# End Source File
# Begin Source File

SOURCE=.\DB_PASIsland.h
# End Source File
# Begin Source File

SOURCE=.\DB_PASMeasure.h
# End Source File
# Begin Source File

SOURCE=.\DB_PASParam.h
# End Source File
# Begin Source File

SOURCE=.\DB_PASRuninfo.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwBus.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwGen.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwLine.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwLoad.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwShuntSreact.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwStation.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwSwitch.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwTfm.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwTfmTap.h
# End Source File
# Begin Source File

SOURCE=.\DB_pwZone.h
# End Source File
# Begin Source File

SOURCE=.\Dialog_Log.h
# End Source File
# Begin Source File

SOURCE=.\IDbInterface.h
# End Source File
# Begin Source File

SOURCE=.\LoginDialog.h
# End Source File
# Begin Source File

SOURCE=.\Open3000Model.h
# End Source File
# Begin Source File

SOURCE=.\Open3000Real.h
# End Source File
# Begin Source File

SOURCE=.\Parse.h
# End Source File
# Begin Source File

SOURCE=.\ParseDataFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseDataFileDlg.h
# End Source File
# Begin Source File

SOURCE=.\RealDataBase.h
# End Source File
# Begin Source File

SOURCE=.\RealSearth.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Utils.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ParseDataFile.ico
# End Source File
# Begin Source File

SOURCE=.\res\ParseDataFile.rc2
# End Source File
# Begin Source File

SOURCE=.\res\right.ico
# End Source File
# Begin Source File

SOURCE=.\res\wrong.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project

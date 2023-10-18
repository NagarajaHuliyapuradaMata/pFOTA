COLOR a
@echo off
set MAKESUPPORT_DIR=%~dp0\MakeSupport
if "%MAKESUPPORT_DIR% "==" "   goto ErrorNotSet
if not exist %MAKESUPPORT_DIR% goto ErrorWrongPath
set PATH_OLD=%PATH%
set PATH=%MAKESUPPORT_DIR%\cmd;%PATH%
set CYGWIN=nodosfilewarning
%MAKESUPPORT_DIR%\cmd\make -C %~dp0 --no-print-directory %*
SET GNU_MAKE_RETURN_CODE=%ERRORLEVEL%
set PATH=%PATH_OLD%
set PATH_OLD=
goto End

:ErrorNotSet
echo ************************************************************************
echo BRS warning: MAKESUPPORT_DIR has to be set to MakeSupport\cmd directory!
echo              Please correct setting in this batch file and try again!
echo ************************************************************************
goto End

:ErrorWrongPath
echo ************************************************************************
echo BRS warning: %MAKESUPPORT_DIR% does not exist
echo              Please correct setting in this batch file and try again!
echo ************************************************************************
goto End

:End
cd ..\..\..\pRealEcu\cL_R2023.09.01\make\01_production
call create_production_file.bat
cd ..\..\..\..\pFOTA\cL_R2023.09.01\make
echo.
set MAKESUPPORT_DIR=
exit /b %GNU_MAKE_RETURN_CODE%

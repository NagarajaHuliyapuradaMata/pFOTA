@echo off
call m.bat -j4 %1 %2 %3 %4 %5 %6 %7 %8 %9


echo ##########################################################
echo # Create Production hex file                             #
echo ##########################################################
cd..
cd .\02_Make\01_merge_hex
call create_production_file.bat
cd..
cd..
cd 08_Make_FBL_CCC
echo.

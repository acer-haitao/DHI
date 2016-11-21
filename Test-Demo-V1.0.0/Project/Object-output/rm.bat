
@echo off
set D:\STM32-SRC\Test-Demo-V1.0.0\Project\Object-output
set a=rm.bat& set b=Test.hex& set c=STM32-Demo-Test.hex
setlocal enabledelayedexpansion
for /f "tokens=* delims=" %%i in ('dir /b/a-d "%d%"') do (set f=%%~nxi
if not !f!==%a% (if not !f!==%b% (if not !f!==%c% (del /f/s/q "%%~fi"))))
pause
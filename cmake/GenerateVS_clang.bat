@echo off

CD ..
set ROOT=%cd:\=/%
set LLVM=%ROOT%/3rdParty/Toolchain/llvm

set LLVMInstallDir=%LLVM%
set "LLVMToolsVersion=22"



if exist "%ROOT%/Build/VisualStudio" rmdir /s /q "%ROOT%/Build/VisualStudio"


cmake -S "%ROOT%" ^
    -B "%ROOT%/Build/VisualStudio" ^
    -G "Visual Studio 17 2022" ^
    -T "ClangCL" ^
    -DCMAKE_C_COMPILER="%LLVM%/bin/clang-cl.exe" ^
    -DCMAKE_CXX_COMPILER="%LLVM%/bin/clang-cl.exe"

pause

pause
@echo off

set ROOT=..
set LLVM=%ROOT%\3rdParty\Toolchain\clang

cmake -S "%ROOT%" ^
    -B "%ROOT%\Build\VisualStudio" ^
    -G "Visual Studio 17 2022" ^
    -T ClangCL ^
    -DCMAKE_C_COMPILER="%LLVM%\clang-cl.exe" ^
    -DCMAKE_CXX_COMPILER="%LLVM%\clang-cl.exe"

pause

pause
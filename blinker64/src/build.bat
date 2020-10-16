@ECHO off

SET ToolChainPath=C:\Tools\gcc\aarch64\bin
SET GCC_Compile="%ToolChainPath%\aarch64-linux-gnu-gcc.exe"
SET GCC_Linker="%ToolChainPath%\aarch64-linux-gnu-ld.exe"
SET GCC_Copy="%ToolChainPath%\aarch64-linux-gnu-objcopy.exe"

SET OutputKernelName=kernel8

SET CompilerFlags=-march=armv8-a+crc -mcpu=cortex-a53
SET CompilerFlags=%CompilerFlags% -mlittle-endian
SET CompilerFlags=%CompilerFlags% -O2 -Wall -ffreestanding -nostdinc -nostdlib -nostartfiles
SET LinkerFlags=-nostdlib -nostartfiles

IF NOT EXIST ..\bin MKDIR ..\bin
PUSHD ..\bin

%GCC_Compile% %CompilerFlags% -c ..\src\main.c -o main.o
%GCC_Compile% %CompilerFlags% -c ..\src\start.S -o start.o
%GCC_Linker% %LinkerFlags% start.o main.o -T ..\src\link.ld -o kernel.elf
%GCC_Copy% kernel.elf -O binary %OutputKernelName%.img

del *.elf 2> NUL
del *.o   2> NUL

POPD

@ECHO off

SET ToolChainPath=C:\Tools\gcc\aarch32\bin
SET GCC_Compile="%ToolChainPath%\arm-none-eabi-gcc.exe"
SET GCC_Linker="%ToolChainPath%\arm-none-eabi-ld.exe"
SET GCC_Copy="%ToolChainPath%\arm-none-eabi-objcopy.exe"

SET OutputKernelName=kernel

SET CompilerFlags=-march=armv8-a+crc -mcpu=cortex-a53 -mfpu=crypto-neon-fp-armv8 
SET CompilerFlags=%CompilerFlags% -mfloat-abi=hard -mlittle-endian
SET CompilerFlags=%CompilerFlags% -O2 -Wall -ffreestanding -nostdinc -nostdlib -nostartfiles
SET LinkerFlags=-nostdlib -nostartfiles

IF NOT EXIST ..\bin MKDIR ..\bin
PUSHD ..\bin

%GCC_Compile% %CompilerFlags% -c ..\src\main.c -o main.o
%GCC_Linker% %LinkerFlags% main.o -T ..\src\link.ld -o kernel.elf
%GCC_Copy% kernel.elf -O binary %OutputKernelName%.img

del *.elf 2> NUL
del *.o   2> NUL

POPD

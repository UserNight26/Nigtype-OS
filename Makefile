# Compiladores e Ferramentas
CC = gcc
CXX = g++
AS = nasm

# Flags para Kernel 32-bit (Padrão NigType-OS)
CFLAGS = -m32 -ffreestanding -O2
CXXFLAGS = -m32 -ffreestanding -O2 -fno-exceptions -fno-rtti
LDFLAGS = -m32 -nostdlib -T linker.ld

# OBJETOS BASEADOS NA SUA ESTRUTURA:
OBJ = boot.o \
      kernel.cpp.o \
      drivers/nigtype_gui_system.o \
      apps/terminal.o

# Regra principal para gerar o binário
nigtype_os.bin: $(OBJ)
	ld $(LDFLAGS) -o nigtype_os.bin $(OBJ)

# Boot está na raiz (boot.s)
boot.o: boot.s
	$(AS) -f elf32 boot.s -o boot.o

# Kernel está na raiz (kernel.cpp)
kernel.cpp.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.cpp.o

# GUI está em drivers/
drivers/nigtype_gui_system.o: drivers/nigtype_gui_system.cpp
	$(CXX) $(CXXFLAGS) -c drivers/nigtype_gui_system.cpp -o drivers/nigtype_gui_system.o

# Terminal está em apps/
apps/terminal.o: apps/terminal.cpp
	$(CXX) $(CXXFLAGS) -c apps/terminal.cpp -o apps/terminal.o

clean:
	rm -f *.o drivers/*.o apps/*.o nigtype_os.bin

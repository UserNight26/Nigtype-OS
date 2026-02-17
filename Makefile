# Compiladores
CC = gcc
CXX = g++
AS = nasm

# Flags para Kernel 32-bit (NigType-OS Standard)
CFLAGS = -m32 -ffreestanding -O2
CXXFLAGS = -m32 -ffreestanding -O2 -fno-exceptions -fno-rtti
LDFLAGS = -m32 -nostdlib -T linker.ld

# OBJETOS (Baseado na lista de arquivos que você mandou)
OBJ = boot.o \
      kernel.cpp.o \
      drivers/nigtype_gui_system.o \
      apps/terminal.o

# 1. REGRA PARA GERAR O ARQUIVO .IMG (O arquivo único que você baixa)
image: nigtype_os.bin
	@echo "--- Gerando arquivo final do NigType-OS ---"
	dd if=/dev/zero of=nigtype_os.img bs=512 count=2880
	dd if=nigtype_os.bin of=nigtype_os.img conv=notrunc

# 2. REGRA PARA LINKAR OS ARQUIVOS
nigtype_os.bin: $(OBJ)
	ld $(LDFLAGS) -o nigtype_os.bin $(OBJ)

# 3. COMO COMPILAR CADA ARQUIVO (Respeitando suas pastas)
boot.o: boot.s
	$(AS) -f elf32 boot.s -o boot.o

kernel.cpp.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.cpp.o

drivers/nigtype_gui_system.o: drivers/nigtype_gui_system.cpp
	$(CXX) $(CXXFLAGS) -c drivers/nigtype_gui_system.cpp -o drivers/nigtype_gui_system.o

apps/terminal.o: apps/terminal.cpp
	$(CXX) $(CXXFLAGS) -c apps/terminal.cpp -o apps/terminal.o

# LIMPAR TUDO
clean:
	rm -f *.o drivers/*.o apps/*.o nigtype_os.bin nigtype_os.img

#!/bin/bash

# 1. Compila tudo usando o Makefile que já fizemos
make clean
make

# 2. Cria uma imagem de disco de 1.44MB (padrão de boot) preenchida com zeros
dd if=/dev/zero of=nigtype_os.img bs=512 count=2880

# 3. Copia o kernel compilado para dentro da imagem de disco
# O 'conv=notrunc' garante que não vamos apagar o resto do arquivo
dd if=nigtype_os.bin of=nigtype_os.img conv=notrunc

echo "----------------------------------------"
echo "NigType-OS: nigtype_os.img criado com sucesso!"
echo "----------------------------------------"

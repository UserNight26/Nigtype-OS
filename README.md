# 🚀 NigType-OS:

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Assembly](https://img.shields.io/badge/Assembly-6E4C13?style=for-the-badge&logo=assembly&logoColor=white)
![Build](https://img.shields.io/badge/Build-Makefile-013243?style=for-the-badge&logo=gnu-bash&logoColor=white)

O **NigType-OS** é um sistema operacional x86 de 32 bits desenvolvido do zero. Focado em uma arquitetura de **Frames Modulares**, ele ignora padrões comerciais para criar uma experiência de usuário bruta e autêntica.

---

## 💻 Requisitos do Sistema (Versão Alvo)

* **Arquitetura:** x86 (IA-32)
* **Memória RAM:** 32 MB (Mínimo) / 128 MB (Recomendado)
* **Gráficos:** Compatível com VGA / VBE
* **Boot:** Legacy BIOS

---

## 🛠️ Como Compilar e Criar o Arquivo Único

Siga estes passos para gerar o arquivo `.img` que contém todo o sistema:

1. **Limpeza de Build:**
´´´

## 📂 Mapa de Arquivos (Project Tree)


NigType-OS/
├── apps/               # Apps nativos (Ex: terminal.cpp)
├── drivers/            # GUI System (nigtype_gui_system.cpp)
├── include/            # Definições (nigtype.hpp)
├── kernel/             # O Núcleo (kernel.cpp)
├── boot.s              # Entrada do Hardware (Assembly)
├── linker.ld           # Arquiteto de Memória
└── Makefile            # O Cérebro da Compilação

## 🎨 Identidade Visual (NigType-OS Original)

O design deste sistema foi criado para ser disruptivo. Ele utiliza o **Frame System**, que se baseia em:
- **Geometria de Controle:** Botões de controle em formatos de quadrados sólidos (Sem ícones de terceiros).
- **Foco em Contraste:** Uso de cores sólidas e bordas rígidas para máxima performance.
- **Estrutura Modular:** Cada janela é tratada como um Frame independente, garantindo um visual limpo.

---

## 📝 Roadmap de Desenvolvimento

- [x] Bootloader Assembly funcional
- [x] Kernel Core (Modo Protegido 32-bit)
- [x] Sistema de Interface (NigType GUI)
- [ ] Implementação de Drivers de Teclado
- [ ] Shell de Comando (Terminal) em `/apps`
- [ ] Suporte a Sistemas de Arquivos (FAT12/16)

---
*NigType-OS é um projeto independente. Design e código por NigType.*


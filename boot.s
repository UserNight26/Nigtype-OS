; =============================================================================
; NigType-OS - Bootloader Entry Point
; =============================================================================
MBOOT_PAGE_ALIGN    equ 1 << 0
MBOOT_MEM_INFO      equ 1 << 1
MBOOT_HEADER_MAGIC  equ 0x1BADB002
MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

section .multiboot
align 4
    dd MBOOT_HEADER_MAGIC
    dd MBOOT_HEADER_FLAGS
    dd MBOOT_CHECKSUM

section .bss
align 16
stack_bottom:
    resb 65536 ; 64 KiB de Stack (Maior para suportar C++)
stack_top:

section .text
global _start:function (_start.end - _start)
extern kernel_main

_start:
    ; Configura o ponteiro da pilha
    mov esp, stack_top

    ; Reset de flags EFLAGS
    push 0
    popf

    ; Chama o Kernel em C++
    call kernel_main

    ; Caso o kernel retorne, trava a CPU
    cli
.hang:
    hlt
    jmp .hang
.end:

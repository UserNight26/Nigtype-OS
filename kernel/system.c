#include "../include/nigtype.h"

// Escreve um byte em uma porta de hardware (I/O)
void outb(unsigned short port, unsigned char val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

// Lê um byte de uma porta de hardware
unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

// Função para mover blocos de memória (essencial para o explorador de arquivos)
void* memcpy(void* dest, const void* src, int n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    while (n--) *d++ = *s++;
    return dest;
}

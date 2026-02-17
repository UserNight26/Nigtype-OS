#include "../include/nigtype.h"

char wait_for_key() {
    unsigned char scancode;
    while (1) {
        scancode = inb(0x60); // Lê a porta do teclado
        if (!(scancode & 0x80)) break; // Espera uma tecla ser pressionada (não solta)
    }

    // Tabela de caracteres (Teclado US)
    static char kbd_map[] = {
        0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
    };

    return kbd_map[scancode];
}

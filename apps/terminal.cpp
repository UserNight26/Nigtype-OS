#include "../include/nigtype.hpp"
#include "../include/nigtype.h"

// Função auxiliar para comparar strings no Kernel
bool str_compare(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) { s1++; s2++; }
    return *(unsigned char*)s1 == *(unsigned char*)s2;
}

void NigTypeOS::run_terminal() {
    char input_buffer[80];
    int buf_idx = 0;

    print_at("\nNigType-OS Shell v1.0", 0, cursor_y++, 0x0B);
    print_at("root@nigtype:/# ", 0, cursor_y, 0x0A);
    int prompt_x = 16;

    while (true) {
        char c = wait_for_key(); // Usa o driver de teclado real

        if (c == '\n') { // ENTER: Processa o comando
            input_buffer[buf_idx] = '\0';
            cursor_y++;
            
            // Lógica de Comandos Linux
            if (str_compare(input_buffer, "ls")) {
                print_at("bin/  dev/  home/  root/  sys/  chrome.app  calc.app", 2, cursor_y++, 0x0F);
            } 
            else if (str_compare(input_buffer, "clear")) {
                this->clear_screen();
                this->draw_taskbar();
                cursor_y = 2;
            }
            else if (str_compare(input_buffer, "chrome")) {
                this->run_chrome(); // Abre o navegador real
            }
            else if (str_compare(input_buffer, "calc")) {
                this->run_calculator(); // Abre a calculadora real
            }
            else if (str_compare(input_buffer, "help")) {
                print_at("Comandos: ls, clear, chrome, calc, help, exit", 2, cursor_y++, 0x0E);
            }
            else {
                print_at("Erro: comando nao encontrado.", 2, cursor_y++, 0x0C);
            }

            // Reseta o prompt
            print_at("root@nigtype:/# ", 0, cursor_y, 0x0A);
            buf_idx = 0;
        } 
        else if (c == '\b' && buf_idx > 0) { // Backspace
            buf_idx--;
            print_at(" ", prompt_x + buf_idx, cursor_y, 0x0F);
        } 
        else if (buf_idx < 79) { // Digitação normal
            input_buffer[buf_idx++] = c;
            char s[2] = {c, '\0'};
            print_at(s, prompt_x + buf_idx - 1, cursor_y, 0x0F);
        }
    }
}

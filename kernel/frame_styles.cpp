#include "../include/nigtype.hpp"
#include "../include/nigtype.h"
#include "../include/gui.hpp" // Inclui o header da GUI

extern "C" void kernel_main() {
    // ... (Seu código de boot e instalação continua aqui) ...

    // Ativa o Modo Gráfico VBE (Exemplo para 1024x768 com 32-bit de cor)
    // O framebuffer_address viria do Multiboot (GRUB)
    unsigned int* framebuffer_address = (unsigned int*)0xFD000000; 
    int screen_width = 1024;
    int screen_height = 768;
    GUI::init_graphics(framebuffer_address, screen_width, screen_height);

    // Agora desenhamos a barra de tarefas em pixels
    GUI::draw_rect(0, 0, screen_width, 30, COLOR_DARK_GREY_RGB); // Barra superior
    GUI::draw_string(10, 8, "NigType-OS", COLOR_WHITE_RGB);

    // Exemplo de uma janela do Chrome
    int chrome_x = 50;
    int chrome_y = 50;
    int chrome_w = 600;
    int chrome_h = 400;

    GUI::draw_window_border(chrome_x, chrome_y, chrome_w, chrome_h, "NigType Chrome - Google.com");
    GUI::draw_close_button(chrome_x + chrome_w - 20, chrome_y + 2);
    GUI::draw_maximize_button(chrome_x + chrome_w - 40, chrome_y + 2);
    GUI::draw_minimize_button(chrome_x + chrome_w - 60, chrome_y + 2);

    // Exemplo de uma janela da Calculadora
    int calc_x = 700;
    int calc_y = 100;
    int calc_w = 250;
    int calc_h = 300;
    GUI::draw_window_border(calc_x, calc_y, calc_w, calc_h, "NigType Calculadora");
    GUI::draw_close_button(calc_x + calc_w - 20, calc_y + 2);

    while(1); // Mantém o sistema vivo
}

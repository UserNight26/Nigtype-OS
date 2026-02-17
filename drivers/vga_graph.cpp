#include "../include/nigtype.hpp"

// Endereço do Linear Framebuffer (LFB) para gráficos reais
unsigned int* framebuffer = (unsigned int*)0xFD000000; 

void draw_pixel(int x, int y, int color) {
    framebuffer[y * 1024 + x] = color; // Assume resolução 1024x768
}

// Desenha a barra superior grossa com cor sólida
void draw_real_taskbar() {
    for(int y = 0; y < 30; y++) { // 30 pixels de altura
        for(int x = 0; x < 1024; x++) {
            draw_pixel(x, y, 0x333333); // Cinza escuro profissional
        }
    }
}

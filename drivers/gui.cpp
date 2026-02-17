#include "../include/gui.hpp"

// Inicializa variáveis estáticas
unsigned int* GUI::framebuffer = nullptr;
int GUI::screen_width = 0;
int GUI::screen_height = 0;

void GUI::init_graphics(unsigned int* fb, int width, int height) {
    framebuffer = fb;
    screen_width = width;
    screen_height = height;
}

void GUI::draw_pixel(int x, int y, unsigned int color) {
    if (x >= 0 && x < screen_width && y >= 0 && y < screen_height) {
        framebuffer[y * screen_width + x] = color;
    }
}

void GUI::draw_rect(int x, int y, int width, int height, unsigned int color) {
    for (int j = y; j < y + height; j++) {
        for (int i = x; i < x + width; i++) {
            draw_pixel(i, j, color);
        }
    }
}

void GUI::draw_string(int x, int y, const char* str, unsigned int color) {
    // Implementacao basica de fonte bitmap aqui (ou usa modo texto temporario)
    // Para um OS real, você carregaria fontes TrueType aqui.
    // Por enquanto, vamos simular no modo de pixels com rects
    int char_width = 8; // Supondo uma largura de caractere
    for (int i = 0; str[i] != '\0'; i++) {
        // Apenas para demonstrar que está "escrevendo"
        draw_rect(x + (i * char_width), y, char_width - 1, 8, color); 
    }
}

// =======================================================
// === DESIGN DE BORDA DE JANELA E ÍCONES REAIS ===
// =======================================================

void GUI::draw_window_border(int x, int y, int width, int height, const char* title) {
    // Barra de título da janela (cor azul escura)
    draw_rect(x, y, width, 20, COLOR_BLUE_RGB); 
    draw_string(x + 5, y + 5, title, COLOR_WHITE_RGB); // Título em branco

    // Borda da janela (cinza escuro)
    draw_rect(x, y, width, 1, COLOR_DARK_GREY_RGB); // Topo
    draw_rect(x, y + height - 1, width, 1, COLOR_DARK_GREY_RGB); // Base
    draw_rect(x, y + 1, 1, height - 2, COLOR_DARK_GREY_RGB); // Esquerda
    draw_rect(x + width - 1, y + 1, 1, height - 2, COLOR_DARK_GREY_RGB); // Direita

    // Área do cliente da janela (cinza claro)
    draw_rect(x + 1, y + 21, width - 2, height - 22, COLOR_LIGHT_GREY_RGB);
}

void GUI::draw_close_button(int x, int y) {
    // Fundo vermelho
    draw_rect(x, y, 18, 18, COLOR_RED_RGB);
    // Desenha um "X" em branco (simples com 2 linhas)
    draw_rect(x + 4, y + 8, 10, 2, COLOR_WHITE_RGB); // Linha horizontal do X
    draw_rect(x + 8, y + 4, 2, 10, COLOR_WHITE_RGB); // Linha vertical do X
}

void GUI::draw_maximize_button(int x, int y) {
    // Fundo verde
    draw_rect(x, y, 18, 18, COLOR_GREEN_RGB);
    // Desenha um quadrado em branco
    draw_rect(x + 4, y + 4, 10, 10, COLOR_WHITE_RGB);
    draw_rect(x + 5, y + 5, 8, 8, COLOR_GREEN_RGB); // "Oco"
}

void GUI::draw_minimize_button(int x, int y) {
    // Fundo azul
    draw_rect(x, y, 18, 18, COLOR_BLUE_RGB);
    // Desenha um traço em branco
    draw_rect(x + 4, y + 8, 10, 2, COLOR_WHITE_RGB);
}


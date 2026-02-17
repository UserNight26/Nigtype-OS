#include "../include/gui.hpp"

// Função de desenho de bordas e ícones (Sem frescura de neon)
void draw_nigtype_frame(int x, int y, int w, int h, const char* label) {
    // 1. Borda Simples Branca (Ou a cor que você preferir no lugar de 0xFFFFFF)
    GUI::draw_rect_outline(x, y, w, h, 0xFFFFFF); 
    
    // 2. Barra de Título (Fundo Preto)
    GUI::draw_rect(x + 1, y + 1, w - 2, 24, 0x000000);
    
    // 3. Texto do Título (Branco)
    GUI::draw_string(x + 10, y + 7, label, 0xFFFFFF);
    
    // --- BOTÕES DE CONTROLE ---
    int x_ctrl = (x + w) - 50;
    int y_ctrl = y + 6;

    // FECHAR (Quadrado Vermelho Sólido)
    GUI::draw_rect(x_ctrl + 30, y_ctrl, 12, 12, 0xFF0000); 
    
    // MAXIMIZAR (Quadrado Verde Sólido)
    GUI::draw_rect(x_ctrl + 15, y_ctrl, 12, 12, 0x00FF00);

    // MINIMIZAR (Quadrado Azul Sólido)
    GUI::draw_rect(x_ctrl, y_ctrl, 12, 12, 0x0000FF);

    // 4. Área de Conteúdo (Fundo Escuro/Cinza)
    GUI::draw_rect(x + 1, y + 25, w - 2, h - 26, 0x1A1A1A);
}

void render_nigtype_interface() {
    // Chamando os frames para os seus apps
    draw_nigtype_frame(50, 50, 600, 400, "NigType-Chrome");
    draw_nigtype_frame(700, 100, 250, 300, "NigType-Calc");
}

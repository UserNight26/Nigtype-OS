#include "nigtype.hpp"

void NigTypeKernel::put_char(int x, int y, char c, vga_color fg, vga_color bg) {
    const int index = y * VGA_WIDTH + x;
    unsigned short color = (bg << 4 | fg) << 8;
    video_mem[index] = c | color;
}

void NigTypeKernel::write_string(int x, int y, const char* str, vga_color fg, vga_color bg) {
    for (int i = 0; str[i] != '\0'; i++) {
        put_char(x + i, y, str[i], fg, bg);
    }
}

void NigTypeKernel::draw_top_bar(const char* title) {
    // Desenha a "linha grossa" no topo (Y = 0)
    // Usamos LIGHT_GREY para o fundo e BLACK para o texto
    for (int x = 0; x < VGA_WIDTH; x++) {
        put_char(x, 0, ' ', BLACK, LIGHT_GREY);
    }
    write_string(2, 0, title, BLACK, LIGHT_GREY);
    write_string(60, 0, "[ MENU | SETTINGS ]", BLACK, LIGHT_GREY);
}

void NigTypeKernel::clear_screen() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            put_char(x, y, ' ', WHITE, BLACK);
        }
    }
}

extern "C" void kernel_main() {
    NigTypeKernel os;
    
    os.clear_screen();
    // A barra de tarefas do NigType-OS no topo:
    os.draw_top_bar("NigType-OS Kernel v1.0.0");
    
    // O conteúdo principal começa abaixo da barra (Y = 2)
    os.write_string(0, 2, " > Sistema Iniciado com Sucesso...", LIGHT_GREEN, BLACK);
    os.write_string(0, 3, " > Pronto para comandos.", WHITE, BLACK);

    while (true) {
        // Loop infinito para manter o sistema vivo
    }
}

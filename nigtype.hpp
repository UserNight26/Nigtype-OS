#ifndef NIGTYPE_HPP
#define NIGTYPE_HPP

// Cores VGA padrão
enum vga_color {
    BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, 
    LIGHT_GREY = 7, DARK_GREY = 8, LIGHT_BLUE = 9, LIGHT_GREEN = 10, 
    LIGHT_CYAN = 11, LIGHT_RED = 12, LIGHT_MAGENTA = 13, LIGHT_BROWN = 14, WHITE = 15,
};

class NigTypeKernel {
public:
    static const int VGA_WIDTH = 80;
    static const int VGA_HEIGHT = 25;
    unsigned short* video_mem;

    NigTypeKernel() : video_mem((unsigned short*)0xB8000) {}

    void clear_screen();
    void draw_top_bar(const char* title);
    void put_char(int x, int y, char c, vga_color fg, vga_color bg);
    void write_string(int x, int y, const char* str, vga_color fg, vga_color bg);
};

#endif

#ifndef GUI_HPP
#define GUI_HPP

#include "nigtype.hpp" // Inclui seu kernel principal

// Cores (RGB para modo gráfico)
#define COLOR_BLACK_RGB     0x000000
#define COLOR_WHITE_RGB     0xFFFFFF
#define COLOR_BLUE_RGB      0x0000FF
#define COLOR_DARK_GREY_RGB 0x333333
#define COLOR_LIGHT_GREY_RGB 0xCCCCCC
#define COLOR_RED_RGB       0xFF0000
#define COLOR_GREEN_RGB     0x00FF00

class GUI {
public:
    static unsigned int* framebuffer; // Ponteiro para a memória de vídeo
    static int screen_width;
    static int screen_height;

    static void init_graphics(unsigned int* fb, int width, int height);
    static void draw_pixel(int x, int y, unsigned int color);
    static void draw_rect(int x, int y, int width, int height, unsigned int color);
    static void draw_window_border(int x, int y, int width, int height, const char* title);
    static void draw_close_button(int x, int y);
    static void draw_maximize_button(int x, int y);
    static void draw_minimize_button(int x, int y);
    static void draw_string(int x, int y, const char* str, unsigned int color);
};

#endif

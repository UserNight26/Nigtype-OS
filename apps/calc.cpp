#include "../include/nigtype.hpp"

void NigTypeOS::run_calculator() {
    clear_screen();
    draw_taskbar();
    
    print("Calculadora NigType Ativa\n", 0x0F);
    
    // Lógica Real:
    int a = input_int("Primeiro numero: ");
    int b = input_int("Segundo numero: ");
    char op = input_char("Operacao (+, -, *): ");
    
    int res = 0;
    if (op == '+') res = a + b;
    if (op == '-') res = a - b;
    if (op == '*') res = a * b;

    print("Resultado Real: ", 0x0A);
    print_int(res); // Função que converte número para texto
}

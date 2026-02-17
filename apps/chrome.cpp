#include "../include/nigtype.hpp"

// Aqui é onde você vai escrever as 100 mil linhas do Chrome no futuro
void NigTypeOS::run_chrome() {
    this->clear_area(5, 5, 70, 15); // Limpa o meio da tela para o app
    this->print_at("NigType Chrome v1.0 - Google", 10, 5, 0x1F); // Azul
    this->print_at("URL: http://www.google.com", 10, 7, 0x0F);
    this->print_at("-----------------------------------------", 10, 8, 0x07);
    this->print_at("Bem-vindo ao navegador do NigType-OS!", 10, 10, 0x0A);
}

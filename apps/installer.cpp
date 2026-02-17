#include "../include/nigtype.hpp"
#include "../include/nigtype.h"

void NigTypeOS::run_setup_wizard() {
    // Tela Azul de Instalação (Padrão clássico)
    this->clear_screen_color(0x1F); // Fundo azul, letra branca

    this->print_at("####################################################", 14, 4, 0x1F);
    this->print_at("#            INSTALACAO DO NIGTYPE-OS              #", 14, 5, 0x1F);
    this->print_at("####################################################", 14, 6, 0x1F);

    this->print_at("Bem-vindo ao instalador do NigType-OS.", 16, 9, 0x1F);
    this->print_at("O sistema detectou um disco rigido vazio de 20GB.", 16, 10, 0x1F);
    
    this->print_at("Deseja formatar e instalar o NigType agora?", 16, 13, 0x1E); // Amarelo
    this->print_at("[ENTER] PARA INSTALAR        [ESC] PARA SAIR", 16, 15, 0x1B); // Ciano

    // ESPERA REAL PELO TECLADO (Porta 0x60)
    bool confirmed = false;
    while(!confirmed) {
        unsigned char key = inb(0x60);
        if(key == 0x1C) confirmed = true; // 0x1C é o scancode do ENTER
    }

    // BARRA DE PROGRESSO REAL
    this->print_at("Formatando drive C:/... [##########          ] 50%", 16, 18, 0x1B);
    for(volatile int d = 0; d < 80000000; d++);
    this->print_at("Copiando arquivos...    [####################] 100%", 16, 18, 0x1B);
    for(volatile int d = 0; d < 50000000; d++);

    this->print_at("INSTALACAO CONCLUIDA! Pressione qualquer tecla.", 16, 21, 0x1A); // Verde
    while(inb(0x60) == 0); // Espera outra tecla
}

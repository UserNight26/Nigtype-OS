#include "nigtype.hpp"
#include "nigtype.h"
extern "C" void kernel_main() {
    NigTypeOS os;
    
    // 1. CHUVA DE LETRAS (Boot Log)
    os.clear_screen();
    run_boot_logs(); // Função em C

    // 2. TELA DE CONFIRMACAO (Instalador)
    os.run_setup_wizard(); // Função em C++

    // 3. ENTRADA NO SISTEMA REAL
    os.clear_screen();
    os.draw_taskbar(); // Sua barra grossa no topo
    
    os.print_at("NigType-OS pronto para uso!", 2, 2, 0x0F);
    os.print_at("Clique no menu ou digite 'chrome' no terminal.", 2, 3, 0x07);

    while(1); // Mantém o sistema vivo
}

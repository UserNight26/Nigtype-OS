extern "C" void kernel_main() {
    NigTypeOS os;
    
    // 1. Logs de Boot
    run_boot_logs();

    // 2. Instalador e Confirmação [ENTER]
    os.run_setup_wizard();

    // 3. Sistema Iniciado
    os.clear_screen();
    os.draw_taskbar();
    
    // Inicia o Terminal Linux do NigType-OS
    os.run_terminal();
}

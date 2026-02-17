#include "../include/nigtype.h"

// Simula a rolagem de logs de hardware
void run_boot_logs() {
    const char* logs[] = {
        "NigType-OS Kernel v1.0.0 (x86_32) loading...",
        "Detecting CPU: Intel(R) Core(TM) @ 3.20GHz... [ OK ]",
        "Initializing GDT and IDT tables... [ OK ]",
        "Memory Check: 1048576 KB RAM found... [ OK ]",
        "SATA Controller: Hard Drive detected at Port 0... [ OK ]",
        "PS/2 Controller: Keyboard and Mouse found... [ OK ]",
        "Network Card: Realtek RTL8139 found... [ OK ]",
        "PCI Bus: Scanning for devices... [ DONE ]",
        "Starting NigType Installation Wizard..."
    };

    for(int i = 0; i < 9; i++) {
        print_string_at(logs[i], 0, i, 0x07); // Letras cinzas
        // Delay para o usuário conseguir ler
        for(volatile int d = 0; d < 30000000; d++);
    }
}

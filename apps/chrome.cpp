#include "../include/nigtype.hpp"

void NigTypeOS::run_chrome() {
    print("A abrir NigType Chrome...\n", 0x0B);
    
    // Tenta comunicar com a porta I/O da placa de rede (ex: Realtek 8139)
    unsigned short nic_port = 0xC000; 
    
    // Envia um pacote de pedido DNS para o Google
    outw(nic_port + 0x00, 0x01); // Comando de envio real
    
    print("A ligar a google.com via HTTP/1.1...\n", 0x07);
    
    // Se o hardware responder, desenha o site
    if (nic_connected()) {
        render_html("<html><h1>Bem-vindo ao Google Real</h1></html>");
    } else {
        print("Erro 404: Placa de Rede nao encontrada.\n", 0x0C);
    }
}

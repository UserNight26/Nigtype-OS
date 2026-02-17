#ifndef NIGTYPE_H
#define NIGTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);
void idt_install();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

#ifdef __cplusplus
}
#endif

#endif

#ifndef IRQ_H
#define IRQ_H

#include <cpu/idt.h>

void install_irq_dispatcher(int irq_num, void (*irq_dispatcher)(struct interrupt_frame*));
void uninstall_irq_dispatcher(int irq_num);

// only used by idt.c
void irq_handler(struct interrupt_frame* frame);

#endif  // IRQ_H

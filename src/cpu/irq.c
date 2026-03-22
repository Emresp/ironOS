#include <cpu/irq.h>
#include <debug/logging.h>
#include <pmio/pic.h>
#include <stddef.h>

static void (*irq_dispatchers[16])(struct interrupt_frame*);

// catches all IRQs and forwards them to the specialized IRQ handlers
void irq_handler(struct interrupt_frame* frame) {
	int irq_num = frame->vector - 32;

	if (irq_dispatchers[irq_num]) {
		irq_dispatchers[irq_num](frame);
	}

	pic_eoi(irq_num);
}

void install_irq_dispatcher(int irq_num, void (*irq_dispatcher)(struct interrupt_frame*)) {
	irq_dispatchers[irq_num] = irq_dispatcher;
	pic_unset_mask(irq_num);  // activate IRQ line
}

void uninstall_irq_dispatcher(int irq_num) {
	irq_dispatchers[irq_num] = NULL;
	pic_set_mask(irq_num);
}

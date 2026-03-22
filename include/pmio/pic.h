#ifndef PIC_H
#define PIC_H

void init_pic();
void pic_eoi(int irq_num);
void pic_set_mask(int irq_num);
void pic_unset_mask(int irq_num);

#endif  // PIC_H

#ifndef PMM_H
#define PMM_H

#include <limine/limine.h>

// Physical memory manager
// The foundation for VMM (virutal memory manager). Keeps track of physical pages

int pmm_init(const struct limine_memmap_response* mmap, const struct limine_hhdm_response* hhdm);
uintptr_t pmm_alloc();

#endif  // PMM_H

#include "descriptor_tables.h"
#include "monitor.h"
#include "timer.h"

struct multiboot;

int main(struct multiboot *mboot_ptr) {
    init_descriptor_tables();
    monitor_clear();
    asm volatile("sti");
    init_timer(10);
    return 0;
}

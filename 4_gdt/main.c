#include "monitor.h"
#include "descriptor_tables.h"

struct multiboot;

int main(struct multiboot *mboot_ptr) {
    init_descriptor_tables();
    monitor_clear();
    asm volatile("int $0x3");
    asm volatile("int $0x4");
    return 0;
}

#include "descriptor_tables.h"
#include "monitor.h"

struct multiboot;

void init_timer() {
    /* If we wanted to set a frequency. */
    /*
    int frequency = 1;
    u32int divisor = 1193180 * frequency;
    u8int l = (u8int)(divisor & 0xFF);
    u8int h = (u8int)( (divisor>>8) & 0xFF );
    */

    /* But we just want the maximum divisor instead. */
    u8int l = 0xFF;
    u8int h = 0xFF;

    /* Command byte. */
    outb(0x43, 0x36);

    // Send the frequency divisor.
    outb(0x40, l);
    outb(0x40, h);
}

int main(struct multiboot *mboot_ptr) {
    init_descriptor_tables();
    monitor_clear();
    /* Mandatory, because the PIC interrupts are maskable. */
    asm volatile("sti");
    init_timer();
    return 0;
}

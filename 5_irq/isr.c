#include "common.h"
#include "isr.h"
#include "monitor.h"

u32int tick = 0;

void isr_handler(registers_t regs) {
    monitor_write("recieved interrupt: ");
    monitor_write_dec(regs.int_no);
    monitor_write(" ");
    monitor_write_dec(tick++);
    monitor_put('\n');

    /* PIC interrupt. */
    if (regs.int_no >= 31) {
        /*
        Reset slave if from slave.
        40 because that is the first slave: there are 8 master starting at 32.
        */
        if (regs.int_no >= 40)
            outb(0xA0, 0x20);
        /* Reset master. */
        outb(0x20, 0x20);
    }
}

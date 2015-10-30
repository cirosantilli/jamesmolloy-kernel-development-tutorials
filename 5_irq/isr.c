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
    if (regs.int_no >= IRQ_MASTER_0) {
        if (regs.int_no >= IRQ_SLAVE_0)
            outb(PIC_SLAVE_CMD, PIC_CMD_RESET);
        outb(PIC_MASTER_CMD, PIC_CMD_RESET);
    }
}

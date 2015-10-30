#include "common.h"

typedef struct registers {
    u32int ds;
    // Pushed by pusha.
    u32int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32int int_no, err_code;
    // Pushed by the processor automatically.
    u32int eip, cs, eflags, useresp, ss;
} registers_t;

typedef void (*isr_t)(registers_t);
void register_interrupt_handler(u8int n, isr_t handler);

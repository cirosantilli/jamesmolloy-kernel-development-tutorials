// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "descriptor_tables.h"

struct multiboot;

int main(struct multiboot *mboot_ptr)
{
    init_descriptor_tables();
    asm volatile("int $0x0");
    return 0;
}

#include "descriptor_tables.h"
#include "monitor.h"
#include "paging.h"

struct multiboot;

int main(struct multiboot *mboot_ptr)
{
    init_descriptor_tables();
    monitor_clear();
    /* TODO: it is this call that makes things fail. */
    initialise_paging();
    /*
    monitor_write("Hello, paging world!\n");
    u32int *ptr = (u32int*)0xA0000000;
    u32int do_page_fault = *ptr;
    */
    return 0;
}

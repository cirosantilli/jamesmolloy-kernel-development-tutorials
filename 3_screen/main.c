#include "monitor.h"

struct multiboot;

int main(struct multiboot *mboot_ptr)
{
    monitor_clear();
    monitor_write("Hello, world!");
    return 0;
}

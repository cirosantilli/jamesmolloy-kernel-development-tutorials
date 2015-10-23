#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);
void monitor_write_hex(u32int n);

#endif

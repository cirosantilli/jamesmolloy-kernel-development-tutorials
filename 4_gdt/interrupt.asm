extern isr_handler

global isr0:
isr0:
    cli                         ; Disable interrupts firstly.
    call isr_handler
    iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

Improvements:

- add 32 bit flags so that compilation works on x86-64 machines
- remove blobs like `floppy.img`: use `grub-mkrescue` and the distro provided `xorriso` instead
- add QEMU run script
- merge `update_image.sh` and `run_bochs.sh` into the Makefile
- object files not hardcoded on the Makefile. Linker script must specify multiboot header first.
- use the right extension for NASM sources `.asm` instead of `.s`

# jamesmolloy kernel development tutorials

Source code from <http://www.jamesmolloy.co.uk/tutorial_html/index.html> with improved build system and some simplifications.

Behaviour is very close to the tutorial so you can still follow along. This mostly cleans and DRYes up the build.

Improvements from upstream:

- add 32 bit flags so that compilation works on x86-64 machines
- remove blobs like `floppy.img`: use `grub-mkrescue` and the distro provided `xorriso` instead
- add QEMU run script
- migrate to GRUB2
- merge `update_image.sh` and `run_bochs.sh` into the Makefile
- add textual expected output descriptions: website only contains Bochs screenshots
- object files not hardcoded on the Makefile. Linker script must specify multiboot header first.
- use the right extension for NASM sources `.asm` instead of `.s`
- remove `warning: 'struct' declared inside parameter list`

Usage:

    sudo apt-get install bochs bochs-sdl build-essential qemu nasm xorriso

    # Build and run current directory with QEMU.
    cd 3_screen
    make qemu
    cd ../4_gdt
    make qemu

    # With Bochs.
    make bochs

    # Clean current directory.
    make clean

    # From toplevel.
    cd ../

    # Clean all.
    make clean

    # Make all.
    make

Tested on Ubuntu 14.04 AMD64.

TODO:

- tutorials 8 - 10 are not working, because we could not make 8 work on GRUB2. See [8_vfs](8_vfs/README.md).

## About

This is an OS development tutorial that creates progressively complex OSes based on the code of the previous one.

It uses GRUB and C.

Since Molloy did not use source control + bug tracker, a list of known bugs grew at: http://wiki.osdev.org/James_Molloy's_Tutorial_Known_Bugs

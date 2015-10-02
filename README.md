# jamesmolloy kernel development tutorials

Source code from <http://www.jamesmolloy.co.uk/tutorial_html/index.html> with improved build system.

Behaviour is exactly the same as the tutorial so you can still follow along. This only cleans and DRYes up the build.

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

    # Build and run given directory with QEMU.
    make qemu DIR=3_screen
    make qemu DIR=4_gdt

    # With Bochs.
    make bochs DIR=3_screen

    # Clean given directory
    make clean DIR=3_gdt
    make clean DIR=4_gdt

    # An environment variable can also be used.
    export DIR=3_screen
    make qemu
    make clean

Tested on Ubuntu 14.04 AMD64.

TODO:

- tutorials 8 - 10 are not working, because we could not make 8 work on GRUB2. See [8_vfs](8_vfs/README.md).
- make `make` build all, `make clean` clean all

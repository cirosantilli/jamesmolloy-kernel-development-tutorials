# jamesmolloy kernel development tutorials

Fork of source code from: <http://www.jamesmolloy.co.uk/tutorial_html/index.html>

Behaviour is exactly the same as the tutorial so you can still follow along. This only cleans and DRYes up the build.

Usage:

    sudo apt-get install bochs bochs-sdl build-essential qemu nasm xorriso
    make TODO

Tested on Ubuntu 14.04 AMD64.

Improvements from upstream:

- add 32 bit flags so that compilation works on x86-64 machines
- remove blobs like `floppy.img`: use `grub-mkrescue` and the distro provided `xorriso` instead
- add QEMU run script
- merge `update_image.sh` and `run_bochs.sh` into the Makefile
- add textual expected output descriptions: website only contains Bochs screenshots
- object files not hardcoded on the Makefile. Linker script must specify multiboot header first.
- use the right extension for NASM sources `.asm` instead of `.s`

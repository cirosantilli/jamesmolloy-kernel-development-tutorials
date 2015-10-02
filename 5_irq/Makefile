.POSIX:

ASM_EXT ?= .asm
C_EXT ?= .c
ELF_EXT ?= .elf
ELF ?= main$(ELF_EXT)
IMG ?= main.img
OBJ_EXT ?= .o
BOOT_PATH ?= iso/boot

OBJS := $(foreach IN_EXT, $(C_EXT) $(ASM_EXT),$(patsubst %$(IN_EXT), %$(OBJ_EXT), $(wildcard *$(IN_EXT))))

.PHONY: bochs clean qemu

$(IMG): $(ELF)
	cp '$<' '$(BOOT_PATH)'
	grub-mkrescue -o '$@' iso

$(ELF): $(OBJS)
	ld -o '$(ELF)' -melf_i386 -Tlink.ld $(OBJS)

%$(OBJ_EXT): %$(C_EXT)
	gcc -c -Wextra -fno-builtin -fno-stack-protector -m32 -nostdlib -nostdinc -o '$@' '$<'

%$(OBJ_EXT): %$(ASM_EXT)
	nasm -felf -o '$@' '$<'

bochs: $(IMG)
	CYLINDERS="$$(($$(stat -c '%s' '$<') / 512))" && \
	bochs -qf /dev/null \
		'ata0-master: type=disk, path="$<", mode=flat, cylinders='"$$CYLINDERS"', heads=1, spt=1' \
		'boot: disk' \
		'display_library: sdl' \
		'megs: 128'

clean:
	rm -f *$(OBJ_EXT) '$(BOOT_PATH)'/*$(ELF_EXT) *$(ELF_EXT) '$(IMG)'

qemu: $(IMG)
	qemu-system-i386 '$<'

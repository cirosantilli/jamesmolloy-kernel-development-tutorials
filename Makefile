.POSIX:

ASM_EXT ?= .asm
BOOT_PATH ?= iso/boot
C_EXT ?= .c
OBJ_EXT ?= .o

DIR ?=

# If DIR is empty, take actions on every directory.
ifeq ($(strip $(DIR)),)

DIRS := $(filter-out iso/, $(wildcard */))

.PHONY: all clean

all:
	for d in $(DIRS); do \
		$(MAKE) DIR="$$d" ;\
	done

clean:
	for d in $(DIRS); do \
		$(MAKE) '$@' DIR="$$d" ;\
	done

else

ELF_EXT ?= .elf
ELF ?= $(DIR)/main$(ELF_EXT)
IMG ?= $(DIR)/main.img

OBJS := $(foreach IN_EXT, $(C_EXT) $(ASM_EXT),$(patsubst %$(IN_EXT), %$(OBJ_EXT), $(wildcard $(DIR)/*$(IN_EXT)))) boot.o

.PHONY: all bochs clean debug qemu

all: $(IMG)

$(IMG): $(ELF)
	cp '$<' '$(BOOT_PATH)'
	grub-mkrescue -o '$@' iso

$(ELF): $(OBJS)
	ld -o '$(ELF)' -melf_i386 -Tlink.ld $^

$(DIR)/%$(OBJ_EXT): $(DIR)/%$(C_EXT)
	gcc -c -ggdb3 -Wextra -fno-builtin -fno-stack-protector -m32 -nostdlib -nostdinc -std=gnu99 -o '$@' '$<'

NASM_RULE := nasm -felf -o
$(DIR)/%$(OBJ_EXT): $(DIR)/%$(ASM_EXT)
	$(NASM_RULE) '$@' '$<'

boot.o: boot.asm
	$(NASM_RULE) '$@' '$<'

bochs: $(IMG)
	CYLINDERS="$$(($$(stat -c '%s' '$<') / 512))" && \
	bochs -qf /dev/null \
		'ata0-master: type=disk, path="$<", mode=flat, cylinders='"$$CYLINDERS"', heads=1, spt=1' \
		'boot: disk' \
		'display_library: sdl' \
		'megs: 128'

clean:
	rm -f $(OBJS) '$(BOOT_PATH)'/*$(ELF_EXT) '$(ELF)' '$(IMG)'

debug: $(IMG)
	qemu-system-i386 -hda '$<' -S -s &
	gdb $(ELF) -x gdb.gdb

qemu: $(IMG)
	qemu-system-i386 '$<'

endif

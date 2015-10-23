.POSIX:
# This makefile simply forwards to the main Makefile at the toplevel directory.
#
# We do this instead of directly linking to the toplevel Makefile,
# as it makes it easier to reuse the shared files on the toplevel like boot.asm
# without making a new symlink per toplevel file.
#
# Another alternative to this would be to make a directory with shared files,
# and symlink that directory in. But still that requires one extra symlink per directory,
# so this method is better.
.PHONY: all
RULE = $(MAKE) -C ../ $@ DIR='$(notdir $(shell pwd))' $(MAKEFLAGS)
all: ; $(RULE)
%: ; $(RULE)

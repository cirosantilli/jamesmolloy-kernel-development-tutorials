TODO get working without the `floppy.img` blob.

Then like any good intertwined tutorial, this blocks all further examples from working.

I cannot make this work because I was not able to migrate the `menu.lst` `module /initrd` directive from GRUB legacy to GRUB 2.

First:

    mkdir -p img
    sudo mount floppy.img img

`/initrd` comes from `initrd.img`, which is generated from:

    gcc -o make_initrd make_initrd.c
    ./make_initrd

TODO what to do with `test.txt` and `test2.txt`?

Expected output:

    Found file dev
            (directory)
    Found file test.txt
            contents: "Hello, VFS world!"
    Found file test2.txt
            contents: "My filename is test2.txt"

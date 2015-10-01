#!/bin/bash

sudo /sbin/losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt2
sudo cp src/kernel /mnt2/kernel
sudo cp initrd.img /mnt2/initrd
sudo umount /dev/loop0
sudo /sbin/losetup -d /dev/loop0

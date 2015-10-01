#!/bin/bash

sudo /sbin/losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 img
sudo cp src/kernel img
sudo umount /dev/loop0
sudo /sbin/losetup -d /dev/loop0

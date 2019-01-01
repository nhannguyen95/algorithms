## The Boot process

```
Power ON
   |
BIOS (Basic Input/Output System)
Initializes the screen, keyboard and tests the
main memory.
   |
Master Boot Record (MBR)
   |
Boot Loader (e.g. GRUB)
   |
Kernel (Linux OS)
   |
Initial RAM disk (initramfs image)
   |
/sbin/init (parent process)
   |
Command Shell using getty
   |
X Window System
(GUI)
```

## The Linux kernel

When the kernel is loaded in RAM, it immediately initializes and configures the computer’s memory and also configures all the hardware attached to the system. This includes all processors, I/O subsystems, storage devices, etc. The kernel also loads some necessary user space applications.

The kernel then runs `/sbin/init`, this then becomes the initial process. `init`:
- starts other processes to get the system running.
- is responsible for keeping the system running and for shutting it down cleanly.

Traditionally, this process startup was done using conventions that date back to the 1980s and the System V variety of UNIX. However, all major recent distributions have moved away from this and adopted systemd instead.

## systemd

Systems with systemd start up faster than those with earlier init methods. This is largely because it replaces a serialized set of steps with aggressive parallelization techniques, which permits multiple services to be initiated simultaneously.

`/sbin/init` now just points to `/lib/systemd/systemd`; i.e. systemd takes over the init process.

## Linux Filesystems

A partition is a physically contiguous section of a disk, or what appears to be so in some advanced setups.

A filesystem is a method of storing/finding files on a hard disk (usually in a partition). 

Linux systems store their important files according to a standard layout called the Filesystem Hierarchy Standard:
- Linux uses the ‘/’ character to separate paths and does not have drive letters.
- ```
  /bin/    essential user command binaries
  /boot/   static files of the boot loader
  /dev/    device files
  /etc/    host-specific system configuration
  /home/   user home directories
  /lib/    essential shared libraries and kernel modules
  /media/  mount point for removable media
  /mnt/    mount point for a temporarily mounted file systems
  /opt/    add-on application software packages
  /sbin/   system binaries
  /srv/    data for services provided by this system
  /tmp/    temporary files
  /usr/    multi-user utilities and applications
  /var/    variable files
  /root/   home directory for the root user
  /proc/   virtual filesystem documenting kernel and process status as text files
  ```
- All Linux filesystem names are case-sensitive, so `/boot` and `/Boot` are different.


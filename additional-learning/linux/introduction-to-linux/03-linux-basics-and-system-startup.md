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



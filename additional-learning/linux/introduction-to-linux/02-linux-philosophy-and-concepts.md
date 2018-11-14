## Linux Philosophy

- Linux was inspired by UNIX, but it is not UNIX.
- It was written to be a free and open source system to be used in place of UNIX.
- Files are stored in a hierarchical filesystem, with the top node of the system being the `root` or simply `/`.
- Processes, devices, and network sockets are all represented by file-like objects, and can often be worked with using the same utilities used for regular files.

## Linux Terminologies

- **Kernel**: brain of Linux OS. It controls the hardware and makes the hardware interact with applications. Resources: kernel.org.
- **Distribution (distro)**: a collection of programs combined with the Linux kernel to make up a Linux-based OS (e.x. Red Hat Enterprise Linux, Fedora, Ubuntu etc.)
- **Boot Loader**: program that boots the OS (e.x. GRUB, ISOLINUX).
- **Service**: program that runs as a background process (e.x. httpd, nfsd, ntpd, ftpd, named etc.)
- **Filesystem**: method for storing and organizing files in Linux (e.x. ext3, ext4, FAT, XFS, NTFS, Btrfs).
- **X Window System**: provides the standard toolkit and protocol to build graphical user interfaces on nearly all Linux systems.
- **Desktop Environment**: a graphical user interface on top of the OS (e.x. GNOME, KDE, Xfce, Fluxbox etc.)
- **Command Line**: Interface for typing commands on top of the OS.
- **Shell**: Command line interpreter that interprets the command line input and instructs the OS to perform any necessary tasks and commands (e.x. bash, tcsh, zsh etc.).

## Linux Distributions

A full Linux distribution = Linux kernel + a number of other software tools for file related operations, user management, and software package management.

Examples of other essential tools and ingredients provided by distributions:
- C/C++ compiler
- gdb debugger
- core system libraries applications need to link with in order to run
- low-level interface for drawing graphics on the screen
- higher-level desktop environment
- system for installing and updating the various components (including the kernel itself)

Most input line entered at the shell prompt have 3 basic elements:
- Command: `rm`
- Options: `-r`, `-f`
- Arguments: `<folder_name>`

---

**`sudo`** allows users to run programs using the security privileges of another user, generally root (superuser).

Ubuntu: sudo is already always set up for you during installation. Red Hat/Fedora or SUSE/openSUSE families of distributions: set up sudo yourself.

---

Executable programs and scrips could be located at:
- `/bin`
- `/usr/bin`
- `/sbin`
- `/usr/sbin`
- `/usr/local/bin`
- `/usr/local/sbin`
- `/opt`
- user's account space: `/home/student/bin`

---

**`whereis`** looks for packages in a broader range of system directories than **`which`**.

---

**`ssh`**: `ssh username@remote-server.com`.

---

Create a hard (symbolic) link `file2` on `file1`: `ln file1 file2`.

Create a soft (symbolic) link `file3` on `file1`: `ln -s file1 file3`.

Symbolic links take no extra space on the filesystem (unless their names are very long). They are extremely convenient, as they can easily be modified to point to different places. An easy way to create a shortcut from your home directory to long pathnames is to create a symbolic link.

Unlike hard links, soft links can point to objects even on different filesystems, partitions, and/or disks and other media,  which may or may not be currently available or even exist. In the case where the link does not point to a currently available or existing object, you obtain a dangling link.

---

**`cat`**: Used for viewing files that are not very long; it does not provide any scroll-back.

**`less`**: Used to view larger files because it is a paging program. It pauses at each screen full of text, provides scroll-back capabilities, and lets you search and navigate within the file. Note: Use / to search for a pattern in the forward direction and ? for a pattern in the backward direction.

---

**`tail`**: _prints_ the last 10 lines of a file by default, you can change this number: `tail -n 15`.

**`head`**: opposite of `tail`,

---

**`touch`**: To set the date and timestamp of a file to a specific value: `touch -t 12091600 myfile`.

---

### Standard File Streams

When commands are executed, by default there are three standard file streams (or *descriptors*) always open for use: standard input (standard in or stdin), standard output (standard out or stdout) and standard error (or stderr).

Usually, stdin is your keyboard, and stdout and stderr are printed on your terminal.

In Linux, all open files are represented internally by what are called file descriptors. Simply put, these are represented by numbers starting at zero. stdin is file descriptor 0, stdout is file descriptor 1, and stderr is file descriptor 2. Typically, if other files are opened in addition to these three, *which are opened by default*, they will start at file descriptor 3 and increase from there.

### I/O Redirection

If we have a program called **do_something** that reads from stdin and writes to stdout and stderr:

We can change its input source by using the less-than sign:

```do_something < input-file```

If you want to send the output to a file, use the greater-than sign:

```
do_something > output-file

Note: Because stderr is not the same as stdout, error messages will still be seen on the terminal windows in the above command
```

If you want to redirect stderr to a separate file, you use stderr’s file descriptor number:

```
do_something 2> error-file

Note: do_something 1> output-file = do_something > output-file
```

A special shorthand notation can send anything written to file descriptor 2 (stderr) to the same place as file descriptor 1 (stdout):

```
do_something > all-output-file 2>&1

An alternative in bash:
do_something >& all-output-file
```

### Pipes

You can pipe the *output* of one command or program into another as its input:

```
command1 | command2 | command3
```

---

**`grep`**: find the _lines_ that contain one or more specified string.

**`locate`**: find files and directories match specified string.

Using **`find`**:
```
find
.                             // Find in current dir
-name "<string>"              // target to find, can contain wildcard
-type [d|l|f]                 // d: dir, l: symbolic link, f: regular file
-size [+|-|empty]10[c|k|M|G]  // Filter by size (bytes, kilobytes, megabytes, gigabytes)
-exec command {} ';'          // Run command on each found result, {} - squiggly brackets is a
                              // placeholder that will be filled with all the file
                              // names that result from the find expression
```

---

## Packages Management System

2 broad families of package managers:
- those based on Debian.
- those which use RPM as their low-level package manager.

The 2 systems are incompatible, but provide the same features and satisfy the same needs.

2 levels of package managers:

```
Linux                  Debian family       SUSE fam     Red Hat fam
Package Manager             |                 |             |
                            v                 v             v
High Level               apt-get            zypper         yum
                            |                   \         /
Low Level                 dpkg                     rmp
Package Manager               \                  /
                                Linux System
```

Low level takes care of unpacking packages, running scripts, getting the software installed correctly.

High level works with groups of packages, downloads them from vendors, figures out dependencies and dependency resolution.

Be careful: installing a single package could result in many dozens or even hundreds of dependent packages being installed.

apt's native interface is at the command line, includes **`apt-get`** and **`apt-cache`**.

Recent Fedora system replaced yum with `dnf`, which has less historical garbage, nice new capabilities and backwards-compatible with yum.

[How to use](https://prod-edxapp.edx-cdn.org/assets/courseware/v1/f478e1c28b54f5df1d53ef1bc855b2e3/asset-v1:LinuxFoundationX+LFS101x+3T2018+type@asset+block/Basic_Packagaing_Commands.pdf)

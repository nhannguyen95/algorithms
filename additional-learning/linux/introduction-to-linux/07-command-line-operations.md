sudo allows users to run programs using the security privileges of another user, generally root (superuser).

---

Create a hard (symbolic) link `file2` on `file1`: `ln file1 file2`.

Create a soft (symbolic) link `file3` on `file1`: `ln -s file1 file3`.

Symbolic links take no extra space on the filesystem (unless their names are very long). They are extremely convenient, as they can easily be modified to point to different places. An easy way to create a shortcut from your home directory to long pathnames is to create a symbolic link.

Unlike hard links, soft links can point to objects even on different filesystems, partitions, and/or disks and other media,  which may or may not be currently available or even exist. In the case where the link does not point to a currently available or existing object, you obtain a dangling link.

---

`cat`: Used for viewing files that are not very long; it does not provide any scroll-back.

`less`: Used to view larger files because it is a paging program. It pauses at each screen full of text, provides scroll-back capabilities, and lets you search and navigate within the file. Note: Use / to search for a pattern in the forward direction and ? for a pattern in the backward direction.

---

To set the date and timestamp of a file to a specific value: `touch -t 12091600 myfile`.

---






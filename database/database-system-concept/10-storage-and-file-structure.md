Physical storage media (increasing in size, decreasing in speed and price):
- Cache
- Main Memory
- Flash Memory (USBs)
- Magnetic-disk storage (HDD)
- Optical storage (compact disk - CD)
- Tape storage

**Storage device hierarchy**

---

Storage media classification:
- **Volatile storage**: information residing in volatile storage doesn not survive system crashes. Example: *main memory*, *cache*. Access to volatile storage is extremely fast.
- **Nonvolatile storage**: Information residing in nonvolatile storage survives system crashes. Example: *magnetic disk*, *flash*, *optical media*, *magnetic tapes*. Nonvolatile storage is slower than volatile storage.
- **Stable storage**: Information residing in stable storage is "never" lost. Although stable storage is theoretically impossible to obtain, it can be closely approximated by techniques that make data loss extremely unlikely. Updates must be done with care to ensure that a failure during an update to stable storage does not cause a loss of information.

---

A database is mapped into a number of different files that are maintained by the underlying operating system. These files reside permanently on disks.

2 approach to store records (rows):
- Fixed-Length Records
- Variable-Length Records

To organize records in files:
- **Heap file organization**: Any record can be placed any where in the file where there is space for the record. There is no ordering of records. Typically, there is a single file for each relation.
- **Sequential file organization**: Records are stored in sequential order, according to the value of a “search key” of each record (A search key is any attribute or set of attributes).
- **Hashing file organization**: A hash function is computed on some attribute of each record. The result of the hash function specifies in which block of the file the record should be placed.

Since data are transferred between disk storage and main memory in units of a block, it is worthwhile to assign file records to blocks in such a way that a single block contains related records. If we can access several of the records we want with only one block access, we save disk accesses. Since disk accesses are usually the bottleneck in the performance of a database system, careful assignment of records to blocks can pay significant performance dividends.

---

**Data-Dictionary Storage**

A relational database system needs to maintain data about the relations, such as:
- names of the relations.
- names of the attributes of each relation.
- domains and lengths of attributes.
- names of views defined on db, and definitions of those views.
- integrity constraints, etc.
- name of index.

Such "data about data" is referred to as **metadata**.

Relational schemas and metadata about relations are stored in a structure called the **data dictionary** or **system catalog**.

The *principle of locality* states that programs access a relatively small portion of their address at any instant of time. There are 2 different types of locality:
- Temporal locality (locality in time): if an item is referenced, it will tend to be referenced again soon.
- Spatial locality (locality in space): if an item is referenced, items whose addresses are close by will tend to be referenced soon.

---

**Memory hierarchy** is a structure that uses multiple levels of memories. The goal is to present the user with as much memory as is available in the cheapest technology, while providing access at the speed offered by the fastest memory.

> Memory types in increasing order in size and decreasing order in speed, price: SRAM, DRAM, Flash, Magnetic disk.

A memory hierarchy can consist of multiple levels, but data is copied between only two adjacent levels at a time, so we can focus our attention on just two levels:
- The upper level: the one closer to the processor, is smaller, faster and more expensive than:
- The lower level.

> The upper level is smaller and built using faster memory parts

The minimum unit of information that can be either present or not present in the two-level hierarchy is called a **block**.

If the data requested by the processor appears in some block in the upper level, this is called a **hit**. The **hit rate**, or **hit ratio**, is the fraction of memory accesses found in the upper level

If the data is not found in the upper level, the request is called a **miss**, the lower level in the hierarchy is then accessed to retrieve the block containing the requested data. The **miss rate** (`= 1 − hit rate`) is the fraction of memory accesses not found in the upper level.

**Hit time** is the time to access the upper level of the memory hierarchy, which includes the time needed to determine whether the access is a hit or a miss.

The **miss penalty** is the time to replace a block in the upper level with the corresponding block from the lower level, plus the time to deliver this block to the processor.

> The hit time will be much smaller than the time to access the next level in the hierarchy, which is the major component of the miss penalty.

> In most systems, the memory is a true hierarchy, meaning that data cannot be present in level i unless it is also present in level i + 1.


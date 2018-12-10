A query like "Find student whose ID = 123" references only a fraction of the student records. It is inefficient to read the entire student relation just to find one tuple for the ID "123".

Ideally, the system should be able to locate these records directly. To allow these forms of access, we design additional structures that we associate with files.

---

Database-system **indices** play the same role as book indices in libraries. For example, to retrieve a student record given an ID, the database system would look up an index to find on which disk block the corresponding record resides, and then fetch the disk block, to get the appropriate student record.

Keeping a sorted list of students’ ID would not work well on very large databases with thousands of students, since the index would itself be very big => more sophisticated indexing techniques may be used.

2 basic kinds of indices:
- **Ordered indices**: Based on a sorted ordering of the values.
- **Hash indices**: Based on a uniform distribution of values across a range of buckets. The bucket to which a value is assigned is determined by a hash function.

Usage of each technique for both ordered indexing and hashing is best suited to particular database applications, thus must be evaluated on these factors:
- Access types: finding records with a specified attribute value, finding records whose attribute values fall in a specified range, etc.
- Access time
- Insearting time
- Deletion time
- Space overhead

We often want to have more than one index for a file/relation.

An attribute or set of attributes used to look up records in a file/relation is called a **search key**.

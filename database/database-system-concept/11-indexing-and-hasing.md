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

A search key containing more than one attribute is referred to as a **composite search key**.

## Ordered Indices

To gain fast random access to records in a file, we can use an index structure.

Each index structure is associated with a particular search key.
```
For example: index = (ID,)
```

An ordered index stores the values of the search keys in sorted order, and associates with each search key the records that contain it.
```
For example:
Index entry/record      Student: ID  | Name
(1,)  --------------->           1     A
(2,)  --------------->           2     B
(3,)  --------------->           3     C
```

### Dense and Sparse Indices

An **index entry**, or **index record**, consists of a search-key value and pointers to one or more records with that value as their search-key value.

2 types of ordered indices:
- Dense index: an index entry appears for every search-key value in the relation.
  ```
  Example: As the above example
  Search-key: (ID,)
  Search-key value set in the relation: (1, 2, 3)
  Search-key value set of index entries: (1, 2, 3) <- appear for every searh-key value in the relation
  ```
- Sparse index: an index entry appears for only some of the search-key values.
  ```
  Example:
  Index entry/record      Student: ID  | Name
  (1,)  --------------->           1     A
                                   2     B
                                   3     C
  (4,)  --------------->           4     D
  
  Search-key: (ID,)
  Search-key value set in the relation: (1, 2, 3, 4)
  Search-key value set of index entries: (1, 4)
  ```

Comparision:
- Faster to locate a record if having dense index.
- Sparse index saves space, imposes less maintenance overhead.
- => Trade-offs

### Multilevel indices

Suppose we build a dense index on a relation with 1e8 records. Index entries are smaller than data records, so we assume 100 index entries fit on a 4Kb block. Thus our index occupies 1e6 blocks ~ 4Gb.

If this index was small enough to be kept entirely in the main memory, the search time to find an entry is low. However this index is large and we might want to fetch from disk.

If we use binary search to locate an entry, it would require up to `log(1e6)` blocks to be read, this can be costly.

To deal with this problem, we construct a sparse outer index on the original index (it's dense w.r.t the original index), which we now call the inner index. In our example, an inner index with 1e6 blocks would require 1e4 entries in the outer index, which would occupy just 1e4 blocks ~ 40Mb. We can keep outer index in main memory and inner index on disk.

Now to find a record in the relation, we binary search on the outer index first to locate the inner index block that contains the record's search key. Eventually it requires only 1 block read operation (on disk).

### Index Update

Regardless of what form of index is used, every index must be updated whenever a record is either updated, inserted into or deleted from the file.

### B<sup>+</sup> indices

The aforementioned ordered-indexing scheme apply for **sequential file organizations** (index-sequential organization), the disadvantage is that performance degrades as the file grows. To overcome this deficiency, we can use a *B<sup>+</sup>-tree*, which requires fewer disk accesses to locate records.

Beside B+-tree, we also have R-tree and Bitmap data structure for ordered index.

### Automatic creation of Indices

If a relation is declared to have a primary key, most database implementations automatically create an index on the primary key. Whenever a tuple is inserted into the relation, the index can be used to check that the primary key constraint is not violated (that is, there are no duplicates on the primary key value). Without the index on the primary key, whenever a tuple is inserted, the entire relation would have to be read to ensure that the primary-key constraint is satisfied.

## Hash Indices

### Static Hashing

We use a hash function to map search-key values into bucket addresses (the term bucket can be used to denote a unit of storage that can store one or more records, it's typically a disk block).

### Dynamic Hashing

Static hashing imposes serious problems when the database grows over time.

Dynamic hashing techniques allow the hash function to be modified dynamically to accommodate the growth or shrinkage of the database.

One form of dynamic hashing is **extendable hashing**, which copes with changes in database size by splitting and coalescing buckets as the database grows and shrinks.


## Comparison of Ordered Indexing and Hashing

If queries are in this form, it's preferable to use hashing-index technique:

```
select A1, A2, .. , An
from r
where Ai = c;
```

Ordered-index techniques are preferable for these queries:

```
select A1, A2, .., An
from r
where Ai <= c1 and Ai >= c2;
```

Usually the designer will choose ordered indexing unless it is known in advance that range queries will be infrequent, in which case hashing would be chosen.

## Index Definition in SQL

The `attribute_list` is the list of attributes of the relations that form the search key for the index.
```
create index <index_name> on <relation_name> (<attribute_list>);
```

If we wish to declare that the search key is a candidate key, we add the attribute **unique** to the index definition:
```
create unique index <index_name> on <relation_name> (<attribute_list>);
```

If `attribute_list` is not a candidate key, the system will display an error message.

Many db system also provide a way to specify the type of index to be used (B+-tree or hashing).

---

## SUMMARY

2 basic kinds of indices:
- **Ordered Index**
- **Hash Index**

**Ordered Index**:

With a **clustered index / primary index** the rows are stored physically on the disk in the same order as the index. Therefore, there can be only one clustered index.

With a **non clustered index / secondary index** there is a second list that has pointers to the physical rows, the rows order might be different from the index order. You can have many non clustered indices.

An **index entry** consists of a search-key value (the columns that are indexed on) and pointers to one or more records with that value as their search-key value.

2 types of ordered indices:
- **Dense Index**: an index entry appears for every search-key value in the file. Secondary index must be a dense one.
- **Sparse Index**: an index entry appears for only some of the search-key values. Therefore, sparse index can only be used only if it is a clustering index.

Dense Index is faster to locate records. But Sparse Index requires less space and imposes less maintenance overhead for insertions and deletions.

**Multilevel Indices**: Sparse Index on Dense Index, and so on.

A search key on an index that contains more than one columns/attributes is referred to as a **composite search key**, and such an index is called **composite index**.

**B Tree and/or B+ Tree** is most widely used to implement single/composite index, it's a balanced tree.

Why we use B Tree / B+ Tree rather: we use them when when data has to be stored on disk and access to disk is really slow and every single read causes a whole disk block to be loaded from the drive. If we compare B Tree / B+ Tree to other Balanced Binary Search Tree (BBST), their nodes are larger - typically have the size of a disk block (this allows each node to be read in with a single disk operation); so the path for look up will be shorter for B Tree / B+ Tree than for BBSTs; thus the number of accesses to nodes will less those in BBSTs. And since accessing to a node in both kind of trees requires expensively fetching same amount of data from disk anyway, it would be more benificial for the case of B Tree / B+ Tree to have shorter path which leads to fewer disk acceses. The trade off is modifying a N-ary tree is trickier than a binary one.

Difference between B Tree and B+ Tree:
- A B-tree allows search-key values to appear only once (if they are unique), unlike a B+-tree, where a value may appear in a nonleaf node, in addition to appearing in a leaf node => less space used.
- Deletion in a B-tree is more complicated.
- Insertion in a B-tree is only slightly more complicated.
- The space advantages of B-trees are marginal for large indices, and usually do not outweigh the disadvantages that we have noted. Thus, pretty much all database-system implementations use the B+-tree data structure, even if (as we discussed earlier) they refer to the data structure as a B-tree.

Other implementations:
- MySQL supports R-tree indexes, which are used to query spatial data, e.g., "Show me all cities within ten miles of San Francisco, CA."
- bitmap indexes, which allow for almost instantaneous read operations but are expensive to change and take up a lot of space.

To make a choice for indexing techinques, consider:
- Is the cost of periodic reorganization of the index or hash organization acceptable?
- What is the relative frequency of insertion and deletion?
- What types of queries are users likely to use?





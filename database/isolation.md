Transaction isolation levels are defined by the presence or absence of the following read phenomena:
- [Dirty reads](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Dirty_reads).
- [Non-repeatable reads](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Non-repeatable_reads).
- [Phantom reads](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Phantom_reads): this is a special case of non-repeatable reads when Transaction 1 repeats a ranged SELECT ... WHERE query.

---

Two-phase locking is the most common transaction concurrency control method in DBMSs. For example:
- In the Non-repeatable reads example: the first SELECT query will make the row with ID = 1 locked, thus blocking Query 2 from updating until the first transaction was committed or rolled back.
- In the Phantom reads example: Query 1 would result in all records with age in the range 10 to 30 being locked, thus Query 2 would block until the first transaction was committed.

Two major types of locks are utilized:
- Write-lock (exclusive lock) is associated with a database object by a transaction before writing (inserting/modifying/deleting) this object.
- Read-lock (shared lock) is associated with a database object by a transaction before reading this object.

The common interactions between these lock types are defined by blocking behavior as follows:
- An existing write-lock on a database object blocks an intended write upon the same object (already requested/issued) by another transaction by blocking a respective write-lock from being acquired by the other transaction. The second write-lock will be acquired and the requested write of the object will take place (materialize) after the existing write-lock is released.
- A write-lock blocks an intended (already requested/issued) read by another transaction by blocking the respective read-lock .
- A read-lock blocks an intended write by another transaction by blocking the respective write-lock.
- A read-lock does not block an intended read by another transaction. The respective read-lock for the intended read is acquired (shared with the previous read) immediately after the intended read is requested, and then the intended read itself takes place.

Most DBMSs offer a number of transaction isolation levels, which control the degree of locking that occurs when selecting data. In decreasing order of isolation levels, we have:
- [Serializable](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Serializable): keeps read and write locks (acquired on selected data) and range-lock (acquired on ranged query) until the end of the transaction.
- [Repeatable reads](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Repeatable_reads): keeps read and write locks (acquired on selected data) until the end of the transaction.
- [Read committed](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Read_committed):  keeps write locks (acquired on selected data) until the end of the transaction, but read locks are released as soon as the SELECT operation is performed.
- [Read uncommitted](https://en.wikipedia.org/wiki/Isolation_(database_systems)#Read_uncommitted)

Note:
- When attempting to maintain the highest level of isolation, a DBMS usually acquires locks on data which may result in a loss of concurrency. This requires adding logic for the application to function correctly.
- If higher isolation levels are used, the possibility of deadlock is increased, which also requires careful analysis and programming techniques to avoid.
- A higher isolation level reduces the types of concurrency effects that users may encounter, but requires more system resources and increases the chances that one transaction will block another.
- Constraining database access operation execution typically means reduced performance (rates of execution).


---

The default isolation level of different DBMS's varies quite widely

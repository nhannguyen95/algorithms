Collections of operations that form a single logical unit of work are called **transactions**.

A database system must maintain the following properties of the transactions:

- **Atomicity**: Either all operations of the transaction are reflected properly in the database, or none are.
  > The database system keeps track (on disk) of the old values of any data on which a transaction performs a write in a log file. If the transaction does not complete its execution, the database system restores the old values from the log to make it appear as though the transaction never executed.
  
- **Consistency**: Execution of a transaction in isolation (that is, with no other transaction executing concurrently) preserves the consistency of the database.

- **Isolation**: Even though multiple transactions may execute concurrently, the system guarantees that, for every pair of transactions Ti and Tj , it appears to Ti that either Tj finished execution before Ti started or Tj started execution after Ti finished.Thus,each transaction is unaware of other transactions executing concurrently in the system.
  > However, concurrent execution of transactions provides significant performance benefits. Other solutions have therefore been developed; they allow multiple transactions to execute concurrently.
  
- **Durability**: After a transaction completes successfully, the changes it has made to the database persist, even if there are system failures.

These properties are often called the **ACID properties**.

---

**Aborted transaction**: a transaction that does not complete its execution successfully. If we are to ensure the atomicity property, an aborted transaction must have no effect on the state of the database. Thus, any changes that the aborted transaction made to the database must be undone.

Once the changes caused by an aborted transaction have been undone, we say that the transaction has been **rolled back** (done by maintaining a *log* as mentioned).

A transaction that completes its execution successfully is said to be **committed**.

A transaction is said to have **terminated** if it has either committed or aborted.

---

To ensure the consistency when having concurrent execution of transactions, it's easy to insist that transactions run serially.

However there are 2 good reasons for allowing concurrency:
- Improved throughput and resource utilization: I/O activities can be done in parallel.
- Reduced waiting time and average response time.

The database system must control the interaction among the concurrent trans- actions to prevent them from destroying the consistency of the database. It does so through a variety of mechanisms called **concurrency-control schemes**.

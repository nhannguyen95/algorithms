Collections of operations that form a single logical unit of work are called **transactions**.

A database system must maintain the following properties of the transactions:

- **Atomicity**: Either all operations of the transaction are reflected properly in the database, or none are.
  > The database system keeps track (on disk) of the old values of any data on which a transaction performs a write in a log file. If the transaction does not complete its execution, the database system restores the old values from the log to make it appear as though the transaction never executed.
  
- **Consistency**: Execution of a transaction in isolation (that is, with no other transaction executing concurrently) preserves the consistency of the database.

- **Isolation**: Even though multiple transactions may execute concurrently, the system guarantees that, for every pair of transactions Ti and Tj , it appears to Ti that either Tj finished execution before Ti started or Tj started execution after Ti finished. Thus,each transaction is unaware of other transactions executing concurrently in the system.
  > However, concurrent execution of transactions provides significant performance benefits. Other solutions have therefore been developed; they allow multiple transactions to execute concurrently.
  
- **Durability**: After a transaction completes successfully, the changes it has made to the database persist, even if there are system failures.

These properties are often called the **ACID properties**.

---

**Aborted transaction**: a transaction that does not complete its execution successfully. If we are to ensure the atomicity property, an aborted transaction must have no effect on the state of the database. Thus, any changes that the aborted transaction made to the database must be undone.

Once the changes caused by an aborted transaction have been undone, we say that the transaction has been **rolled back** (done by maintaining a *log* as mentioned).

A transaction that completes its execution successfully is said to be **committed**.

A transaction is said to have **terminated** if it has either committed or aborted.

---

Transaction-processing systems in databases usually allow multiple transactions to run concurrently. Since this may cause several complications with consistency of the data, it will be easier to insist that transactions run serially instead of concurrently to ensure consistency. 

However there are 2 good reasons for allowing concurrency:
- Improved throughput (the number of transactions executed in a given amount of time) and resource utilization: I/O activities can be done in parallel.
- Reduced waiting time and average response time (the average time for a transaction to be completed after it has been submitted).

That motivates databases to use concurrent execution. If so, the database system must control the interaction among the concurrent transactions to prevent them from destroying the consistency of the database. It does so through a variety of mechanisms called **concurrency-control schemes**.

---

Suppose we have 2 transactions T<sub>1</sub> and T<sub>2</sub>. A schedule on these 2 transactions is an execution sequence that captures the key actions of them that affect concurrent execution, such as read and write operations, while abstracting away internal details of the execution of the transaction. For example a **serial schedule** of T<sub>1</sub> and T<sub>2</sub>:

```
T1             | T2
read(A)        | 
A = A - 50     |
write(A)       |
read(B)        |
B = B + 50     |
write(B)       |
commit         |
               | read(A)
               | temp = A * 0.1
               | A = A - temp
               | write(A)
               | read(B)
               | B = B + temp
               | write(B)
               | commit
```

When the database system executes these 2 transactions concurrently, the corresponding schedule no longer needs to be serial. One possible schedule when T<sub>1</sub> and T<sub>2</sub> are executed concurrently is:

```

T1             | T2
read(A)        | 
A = A - 50     |
write(A)       |
               | read(A)
               | temp = A * 0.1
               | A = A - temp
               | write(A)
read(B)        | 
B = B + 50     | 
write(B)       | 
commit         | 
               | read(B)
               | B = B + temp
               | write(B)
               | commit
```

This schedule arrives at the same state as the aforementioned serial schedule. Obviously, not all concurrent executions result in a correct state, but will result in a *inconsistent state*.

So, it is the job of the database system to ensure the property that any schedule produced by concurrent processing of a set of transactions will have an effect equivalent to a schedule produced when these transactions are run serially in some order (using **concurrency-control schemes**).

A system that guarantees that property is said to ensure **serializability**.

We need to address transaction failures during concurrent execution:
- If a transaction Ti fails, we need to undo the effect of this transaction to ensure the atomicity property of the transaction.
- Any transaction Tj that is dependent on Ti (that is, Tj has read data written by Ti), is also aborted.

To achieve this, we need to place restrictions on the type of schedules permitted in the system:

- **Recoverable schedules**: for each pair of transactions Ti and Tj such that Tj reads a data item previously written by Ti, *the commit operation of Ti appears before the commit operation of Tj*. Otherwise, we have Tj commited while Ti is still active, and if Ti aborted, Tj can't because it's already commited, we call this *nonrecoverable schedules*.

- **Cascadeless schedules**: if a single transaction failure leads to a series of transaction rollbacks, we call this a **cascading rollback**. This is undesirable, since it leads to the undoing of a significant amount of work. It is desirable to restrict the schedules to those where cascading rollbacks cannot occur. Such schedules are called cascadeless schedules: for each pair of transactions Ti and Tj such that Tj reads a data item previously written by Ti, *the commit operation of Ti appears before the read operation of Tj*. It is easy to verify that every cascadeless schedule is also recoverable.

Schedules must be *recoverable*, to make sure that if transaction a sees the effects of transaction b (that is, a has read data written by b), and b then aborts, then a also gets aborted.

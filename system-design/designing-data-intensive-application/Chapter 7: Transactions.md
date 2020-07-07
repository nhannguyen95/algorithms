## ACID

**A transaction** is a way for an application to group several reads and writes together into a logical units. With transactions, error handling becomes much simpler for an application since it doesn't need to worry about partial failure (a transaction result could only be succesfull or failed).

The safety guarantees provided by transactions are often described by the well-known ACID:
- Atomicity:
  - a transaction cannot be broken down into smaller parts.
  - can be implemented using a log for crash recovery.
- Consistency:
  - satements about your data that must always be true.
  - C is a property of the application, (not db)
- Isolation:
  - concurrently executing transactions are isolated from each other (when they try to access same db records).
  - the db ensures that the result is the same as if they had run serially, even though in reality they may have run concurrently.
  - can be implemented using a lock on each object (row).
- Durability: once a transactions has committed successfully, any data it has written won't be forgotten.
  
A and I describe what the db should do if a client makes several writes within the same transaction.

## Usecases

**Use case**: the user table has `unread_email` field that is increased by one when a user has a new email. If a client read the `unread_email` after the new email is sent and before the `unread_email` counter is updated, he gets wrong data.

Dirty read.


## Lock-Based Protocols

One way to ensure isolation is to require that data items be accessed in a mutually exclusive manner: while one transaction is accessing a data item, no other transaction can modify that data item.

The most common method used to implement this requirement is to allow a transaction to access a data item only if it is currently holding a **lock** on that item.




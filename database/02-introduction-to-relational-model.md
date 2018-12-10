In the relational model
- **relation** is used to refer to a table
- **tuple** is used to refer to a row
- **attribute** refers to a column of a table

---

We must differentiate between the **database schema**, which is the logical design of the database, and the **database instance**, which is a snapshot of the data in the database at a given instant in time.

---


A **superkey** is *a set of one or more attributes* that, taken collectively, allow us to identify uniquely a row in the relation.
> A superkey may contain extraneous attributes, for example (ID, name)

We are often interested in superkeys for which no proper subset is a superkey. Such minimal superkeys are called **candidate keys**.

We shall use the term **primary key** to denote a candidate key that is chosen by the database designer.

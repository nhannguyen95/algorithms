---

A major purpose of a database system is to provide users with an abstract view of the data. That is, the system hides certain details of how the data are stored and maintained.


Databases change over time as information is inserted and deleted. The collection of information stored in the database at a particular moment is called an **instance** of the database. The overall design of the database is called the **database schema**. Schemas are changed infrequently.

---

Underlying the structure of a database is the **data model**: a collection of conceptual tools for describing data, data relationships, data semantics, and consistency constraints.

There are a number of different data models:
- **Relational Model**: the most widely deployed mode for storing data in databases, tables are also known as **relations**.
- **Entity-Relationship (E-R) Model**
- **Object-Based Data Model**
- **Semistructured Data Model**

---

A **relational database** is based on the relational model and uses a collection of tables to represent both data and the relationships among those data.

---

There are some computations that are possible using a general-purpose programming language but are not possible using SQL. SQL also does not support actions such as input from users, output to displays, or communication over the network.

---

Design database: what attributes we want to capture in the database and how to group these attributes to form the various tables

The “what” part is basically a business decision.

The “how” part is mainly a computer-science problem, two ways to solve this problem:
- Entity-relationship model:
  > uses a collection of basic objects, called *entities*, and *relationships* among these objects. Entities are described in a database by a set of *attributes*. The overall logical structure (schema) of a database can be expressed graphically by an *entity-relationship (E-R) diagram*. One of the most popular to draw these diagrams is to use the *Unified Modeling Language (UML)*.
- Employ a set of algorithms (collectively known as **[normalization](https://docs.google.com/document/d/1g3ndNEGUm-spxu35GbG2nXyW0tkFVilT9EaaLWlILng/edit?usp=sharing)**) that takes as input the set of all attributes and generates a set of tables.

---

A database system is partitioned into 2 main modules:
- Data storage manager: databases typically require a large amount of storage space, so **the information is stored on disks** (using the file system provided by the operating system). Data are moved between disk storage and main memory as needed. Since the movement of data to and from disk is slow relative to the speed of the central processing unit, it is imperative that the database system structure the data so as to minimize the need to move data between disk and main memory.

  Storage manager:
  - manages the allocation space on disk storage and the data structures used to represent information stored on disk.
  - fetches data from disk storage into main memory, decides what data to cache in main memory.
  - indices: which can provide fast access to data items.
  
- Data query processor: compile, translate and excute queries.

---

Often, several operations on the database form a single logical unit of work, for example it is essential that either both the credit and debit (in a fund transfer) occur, or that neither occur. This all-or-none requirement is called **atomicity**.

A **transaction** is a collection of operations that performs a single logical function in a database application. *Each transaction is a unit of both atomicity and consistency*.

---




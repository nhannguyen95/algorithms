---

**JOINS**:
- **Natural joins**: join 2 or more tables based on common attributes. It produces a relation as the result.

  Example: http://www.sqlfiddle.com/#!17/319f1/1/0 (common attributes are `category_id` and `temp`).

  Notice:
  ```sql
  select A1, A2..
  from r1, r2..  # This is Cartesian product, mean each tuple in the left join with every tuple in the right
  ```
- **General joins**: allows a general predicate over the realtions being joined with the **on** condition.
  ```sql
  select *
  from student join takes on stduent.ID=takes.ID;
  ```

  Natural join and General join are in fact called **inner join** since they do not preserve nonmatched tuples.

  Natural join = natural inner join.

- **Outer joins**: works in a similar manner to the join operations, but preserve those tuples that would be lost in a join, by creating tuples in the result containing null values. 3 forms of outer join:
	- **Left outer join**: preserves tuples in the left relation of the **left outer join** operation.
	- **Right outer join**: preserves tuples in the right relation of the **right outer join** operation.
	- **Full outer join**: preserves tuples in both relations.

**JOIN CONDITIONS**:
- **natural**: join on common (same name) attributes.
- **on**: join on specified predicate.
- **using**: join on specified attributes.

---

**VIEWS**:

To define a view, we give the view a name and state the query that compute the view:
```sql
create view v as <query expressions>;
```

Example:
```sql
create view faculty(ID, name, dept_name) as
select ID, name, dept_name
from instructor;
```

Views are not precomputed and stored until needed.

Once we have defined a view, we can use the view name to refer to the virtual relation that the view generates. View names may appear in a query any place where a relation name may appear:
```sql
select ..
from faculty
where ..
```

When we define a view, the db system stores the definition of the view, rather then the result of evaluation of the query expression that defines the view. Wherever a view relation appears in a query, it is replaced by the stored query expression. Thus, whenever we evaluate the query, the view relation is recomputed. This leads to the essential different between view and materialized view.

**MATERIALIZED VIEWS**: are disk based stored and the db system makes sure that if the actual relations used in the view definition change, the view is kept up-to-date.

The process of keeping the materialized view up-to-date is called **view maintenance**.

View maintenance can be dome immediately when any of the relations on which the view is defined is updated.

Some db system perform view maintenance lazily (i.e. when the view is accessed), some perform periodically (in this case the contents of the materialized view may be stale), some keep the materialized view always up-to-date, some permits the db admin to control which method to be used.

Modifications of db through views may cause problems thus are generally not permitted on view relations, except in limited cases.

In general, an SQL view is said to be **updatable** if the following conditions are all satisfied by the query defining the view:
- **from** clause has only one db relation.
- **select** clause contains only attribute names of the relation (not expressions, aggregates..)
- Any attribute not listed in the **select** can be set to null
- The query does not have **group by** or **having clause**.

---

**TRANSACTIONS**

A transaction consists of a sequence of query and/or update statements.

SQL standard specifies that a transaction begins implicitly when an SQL statement is executed.

One of the following SQL statements must end the transaction: **commit** and **rollback**.

The db system guarantee that in the event of some failure: error in SQL statements, power outage, system crash etc., a transaction's effects will be rolled back if it has not yet executed commit. In case of power outage/system crash, the rollback occurs when the system restarts.

By commit all actions or unro all actions, the db provides an abstract of a transaction as being **atomic** - either all effects of the transaction are reflected in the db, or none are.

---

**The check clause**: to ensure that attribute values satisfy specified conditions:
```sql
create table section(
	course_id varchar(8),
	semester varchar(8),
	primary key (course_id),
	check (semester in ('Fall', 'Winter'))
);
```

---

**Referential Integrity**:
```sql
create table course(
	...
	foreign key(dept_name) references department
		on delete cascade
		on update cascade,
);
```

- **casecade**: if tuple in department is deleted, tuple in course that refers to that tuple is also deleted.
- **set null**: if tuple in department is deleted, tuple in course that refers to that tuple will have the dept_name attribute set to null.

If there is a chain of foreign-key dependencies across multiple relations, a deletion or update at one end of the chain can propagate across the entire chain.

**Integrity Constraint Violation During a Transaction**: Transactions may consist of several steps, and integrity constrants may be violated temporarily after 1 step, but a later step may remove the violation. To handle such situations, the SQL standard allows a clause **initially deferred** to be added to a constraint specification, the constraint would then be checked at the end of a transaction, and not at intermediate steps. However, you should be aware that the default behavior is to check constratins immediately, and many database implementations do not support deferred constraint checking.

---

**SQL Data Types**

- **date**: contains 4-digit year, month and day of the month (2001-04-25).
- **time**: time of day, in hours, minutes, seconds (09:30:00).
- **timestamp**: combination of date and time (2001-04-25 10:29:01.45).

**Large-object types**: it is usually inefficient to retrieve an entire large object into memory. Instead, an application would usually use an SQL query to rerieve a "locator" for a large object and then use the locator to manipulate the object form the host language in which the application is written.
- **clob**
- **blob**
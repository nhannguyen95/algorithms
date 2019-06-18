**FUNCTIONS AND PROCEDURES**

[Differences between Functions and Procedures](https://stackoverflow.com/a/12900448/3852032).

Functions and Procedures allow business logic to be stored in the db, and executed from SQL statement rather than being encoded as programming-language procdures stored entirely outside the db.

**Functions**:

Declare a function:
```sql
# Given name of a department, returns the count of the number of instructors in that department
create function dept_count(dept_name varchar(20))
	returns integer
	begin
	declare d_count integer;
		select count(*) into d_count
		from instructor
		where instructor.dept_name=dept_name
	return d_count;
	end
```

Usage:
```sql
select dept_name, budget
from instructor
where dept_count(dept_name) > 12;
```

SQL standard also supports **table functions** - functions that return tables.

**Procedure**:

Declare a Procedure:
```sql
create procedure dept_count_proc(in dept_name varchar(20), out d_count integer)
	begin
		select count(*) into d_count
		from instructor
		where instructor.dept_name=dept_count_proc.dept_name
	end
```

Usage:
```sql
declare d_count integer;
call dept_count_proc('Physics', d_count);
```

Same name procedures must have different number of arguments.

Same name functions  must either have different number of arguments, or differ in the type of at least one argument.

---

**TRIGGERS**: is a statment that the system executes automatically as a side effect of a modification to the db. To design a trigger mechanism, we must meet 2 requirements:
- Specify WHEN a trigger is to be executed.
- Specify WHAT to be take when the trigger executes.

Once we enter a trigger into the db, the db system takes on the responsibility of executing it whenever the specified event occurs and the corresponding condition is satisfied.

Declare a trigger:
```sql
create trigger timeslot_check1 after insert on section
referencing new row as nrow
for each row
when (nrow.time_slot_id not in (
		select time_slot_id
		from time_slot
	))
begin
	rollback
end;
```

Many db systems support a variety of other triggering events:
- when a user logs on to the db.
- system shuts down
- changes are made to system settings.
- before/after an event (insert/delete/update).

The action of one trigger can set off another trigger, this could lead to an infinite chain of triggering.

Triggers can serve a very useful purpose, but they are best avoided when alternatives exist.

---

**ADVANCED AGGREGATION FEATURES**

**Ranking**

```sql
# Suppose we have a view student_grades(ID, GPA) giving the grade-point average of each student.
select ID, rank() over (order by(GPA) desc) as s_rank
from student_grades
order by s_rank;  # To sort by rank

# The rank function gives the same rank to all tupes that are equal on the order by attributes. We could use dense_rank function to resolve that.

# Ranking can be done within partitions of the data, for instance we wish to rank students by department rather than across the entire university. Assume that we have the view dept_grades(ID, dept_name, GPA):
select ID, dept_name, rank() over (partition by dept_name order by GPA desc) as dept_rank
from dept_grades
order by dept_name, dept_rank;

# SQL permits the user to specify where null values should occur by using nulls first or nulls last:
select ID, rank() over (order by GPA desc nulls last) as s_rank
from student_grades;
```

When ranking occurs along with a **group by** clause, the **group by** clause is applied first, and partitioning and ranking are done on the results of the group by.

**Windowing**: window queries comput an aggregate functino over ranges of tuples, for example to compute an aggregate of a fixed range of time.
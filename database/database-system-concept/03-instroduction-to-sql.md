SQL has several parts:
- **Data-definition language** (DDL): commands for defining/deleting/modifying relation schemas.
- **Data-manipulation language** (DML): abilities to query/insert/delete information from db.
- **Integrity**: commands for specifying integrity constraints that the data in the db must satisfy.
- **View definition**: commands for defining views.
- **Transaction control**: commands for begining and ending transactions.
- **Authorization**: commands for specifying access rights to relations & views.

---

Buildt-in types:
- char(n): fixed-length character string with length n.
  > store "Avi" of type char(10), 7 spaces are appended to make it 10.
  > comparing 2 char string of different lengths, spaces will be added to the shorter one before comparision.
- varchar(n) (character varying): variable-length character string with maximum length n.
  > No appended spaces.
  > When compared with char string, spaces can be appended to varchar to make them same length. This is not always true.
  > Recommend: use varchar instead of char.
  > Many db allow Unicode to be stored.
- int
- smallint
- numeric(p, d)
- real, double precision: machine-dependent precision.
- float(n): precision of at least n digits.

---

Schema definition:
```
create table r
	(A1 D1,
	 A2 D2,
	 ..
	 An Dn,
	 <integrity-constraint1>,
	 <integrity-constraintk>)
```

Example:
```sql
create table department (
	dept_name varchar(20),
	building varchar(15),
	budget numeric(12,2),
	primary key(dept_name),
	foreign key(dept_name) references department
);
```

`drop table r`: delete data and schema for r.

`delete from r`: delete only data, retain relation r.

In the formal definition of relational model, a relation is a set, but duplicate elimination is time-consuming => SQL allows duplicates in relations and results of SQL expressions => Use `select distict` to eliminate duplicates.

---

SQL query has the form:
```sql
select A1, A2, .., An
from r1, r2, .., rm
where P;
```

The easiest way to understand is:
- Step 1: `from`: generate Cartesian product of the relations listed in the `from` clause (note that SQL would execute the query in an more optimized way than this):
  ```
  for each t1 in r1
    for each t2 in r2
      ..
        for each tm in rm
          Concate t = (t1, t2, .., tm)
          Add t into the result relation
  ```
- Step 2: `where`: apply predicates in `where` clause on the result.
- Step 3: For each tuple in the result of step 2, output the attributes specified in the `select` clause.



---

SQL standard specifies that equality operation on strings is case sensitive. Some DB implementations are not though.

Pattern matching with `like` operator:
- Percent (%): match any substring.
- Underscore ( _ ): match any character.

---

**Set Operations**:

**union**: automatically eliminates duplicates, use **union all** to retain them.
```sql
(select, from, where)
union
(select, from, where);
```

**intersect**: automatically eliminates duplicates, use **intersect all** to retain them.
```sql
(select, from, where)
intersect
(select, from, where);
```

**except**: outputs all tuples from first input that do not occur in second input, use **except all** to retain duplicates.
```sql
(select, from, where)
intersect
(select, from, where);
```

---

[**Aggregate Functions**](https://github.com/nhannguyen95/sql-in-10-mins-4th-edition/blob/master/lesson-09-summarizing-data/notes.md):
- sum
- avg
- min
- max
- count: can't use `distinct` with `count(*)`.

[**Aggregate with Grouping**](https://github.com/nhannguyen95/sql-in-10-mins-4th-edition/tree/master/lesson-10-grouping-data): apply the aggregate function not only to a single set of tuples but to also a group of sets of tuples. Tuples with the same value on all attributes in the **group by** clause are placed in one group.
- Any attribute that is not present in the **group by** clause must appear only inside an aggregate function if it appears in the **select** clause, otherwise the query is treated as erroneous.
- Any attribute that is present in the **having** clause without being aggregated must appear in the **group by** clause.

---

[**Nested Subqueries**](https://github.com/nhannguyen95/sql-in-10-mins-4th-edition/tree/master/lesson-11-working-with-subqueries):

A subquery is a **select, from, where** expression that is nested within another query.

**Set Membership**: **in** and **not in** operator:
```sql
select distinct course_id
from section
where semester='Fall' and year=2009 and course_id in # or not in
	(select course_id
	 from section
	 where semester='Spring'
	);

# in and not in used in enumerated sets
select distinct name
from instructor
where name not in ('Mozart', 'Einstein');
```

**Set Comparision**: **some, all**, operator
```sql
# Greater than at least 1
select name
from instructor
where salary > some(
	select salary
	from instructor
	where dept_name='Biology'
);

# Greater than all
select dept_name
from instructor
group by dept_name
having avg(salary) >= all(
	select avg(salary)
	from instructor
	group by dept_name
);

```

**Test for Empty Relations**: **exists** operator used to test if a subquery has any tuples in its result, we also have **non exists**.
```sql
# Courses taught in both Fall 2009 and Spring 2010
select course_id
from section as S  # table alias
where semester='Fall' and year=2009 and exists(
	select *
	from section as T
	where semester='Spring' and year=2010 and S.course_id=T.course_id
);
```

A subquery that uses a correlation name from an outer query is called a **correlated subquery**. According to the rule, in a subquery, it's legal to use only correlation names defined in the subquery itself or in any query that contains the subquery.

**Test for Absence of Duplicate Tuples**: **unique** operator returns **true** if the argument subquery contains no duplicate tuples.

**Subqueries in the From Clause**: any **select, from, where** expression returns a relation as a result can be inserted into another **select, from, where** anywhere that a relation can appear.
```sql
# Find the average instructors' salaries of those departments where the average salary is > $45k
select dept_name, avg_salary
from (
	select dept_name, avg(salary)
	from instructor
	group by dept_name)
	as dept_avg(dept_name, avg_salary)  # give result relation a name and rename attributes
where avg_salary > 42000;
```

**The with Clause**: provides a way of defining a temporary relation whose definition is available only to the query in which the **with** clause occurs
```sql
with max_budget(value) as
	(select max(budget)
	 from department)
select budget
from department, max_budget
where department.budget=max_budget.value
```

**Scalar Subqueyries**: SQL allows subqueries to occur wherever an expression returning a value is permitted, provided the subquery returns only 1 tuple containing a single attribute:
```sql
# List all departements along with the number of instructors in each department
select dept_name,
	(select count(*)
	 from instructor
	 where department.dept_name=instructor.dept_name  # Usage of correlation variables
	) as num_instructors
from department;  # Correlation variables
```

---

We also have: **delete, from, where** and **update, set, where**.

**Case statement**:
```sql
case
  when pred1 then result1
  when pred2 then result2
  ...
  when predn then resultn
  else result0
 end
```

Example:
```sql
update instructor
	set salary=case
				  when salary <= 100000 then salary * 1.05
				  else salary * 1.03
	 		   end
```

Scalar subqueries can also be useful in update statements:
```sql
update student S  # Correlation variable
set tot_cred=(
	select case
		       when sum(credits) is not null then sum(credits)
		       else 0
	       end
	from takes natural join course
	where S.ID=takes.ID and
		takes.grade <> 'F' and
		takes.grade is not null
);
```


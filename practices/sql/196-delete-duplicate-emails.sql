-- Self-join
DELETE p1
FROM person p1,
     person p2
WHERE p1.Email = p2.Email
  AND p1.Id > p2.Id;

-- Subquery
-- https://stackoverflow.com/questions/4429319/you-cant-specify-target-table-for-update-in-from-clause
DELETE FROM Person
WHERE Id NOT IN
(
    SELECT Id
    FROM
    (
        SELECT MIN(Id) AS Id
        FROM Person
        GROUP BY Email
    ) AS Tmp
);

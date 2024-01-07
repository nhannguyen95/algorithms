SELECT now.Id
FROM Weather AS now,
     Weather AS pre
WHERE DATEDIFF(now.Date, pre.Date) = 1
  AND pre.Date IS NOT NULL
  AND now.Temperature > pre.Temperature;

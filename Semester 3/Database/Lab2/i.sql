use [Database];
-- i
-- ANY / ALL

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage >= ALL(
    SELECT e.wage
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage <= ALL(
    SELECT e.wage
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage > ANY(
    SELECT e.wage
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage < ANY(
    SELECT e.wage
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage = (
    SELECT MAX(e.wage)
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage = (
    SELECT MIN(e.wage)
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage NOT IN(
    SELECT MIN(e.wage)
    FROM Employee e
    )
ORDER BY e.wage DESC

SELECT e.fullName, e.wage
FROM Employee e
WHERE e.wage NOT IN (
    SELECT MAX(e.wage)
    FROM Employee e
    )
ORDER BY e.wage DESC
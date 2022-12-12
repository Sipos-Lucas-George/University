use [Database];
-- h
-- GROUP BY

SELECT e.nameOfBusiness, COUNT(*) as numberOfEmployees
FROM Employee e
GROUP BY e.nameOfBusiness
HAVING COUNT(*) >= 1
ORDER BY e.nameOfBusiness DESC

SELECT l.loadSupplierID, COUNT(*) as numberOfLoads
FROM Load l
WHERE loadSupplierID IS NOT NULL
GROUP BY l.loadSupplierID

SELECT e.fullName, MAX(e.wage) as maxWage
FROM Administrator a, Employee e
WHERE EXISTS(
    SELECT AVG(e.wage) as averageWage
    FROM Employee e
    GROUP BY e.nameOfBusiness
    HAVING AVG(e.wage) > 100
    )
GROUP BY e.wage, e.fullName
HAVING MAX(e.wage) > ANY(
    SELECT AVG(e.wage) as averageWage
    FROM Employee e
    GROUP BY e.nameOfBusiness
    HAVING AVG(e.wage) > 50
    )
ORDER BY maxWage DESC

SELECT a.nameOfBusiness, a.fullName, COUNT(*)
FROM Administrator a
GROUP BY a.nameOfBusiness, a.fullName
HAVING COUNT(*) <> (
    SELECT e.c
    FROM (
        SELECT COUNT(*) c
        FROM Employee e
        WHERE e.nameOfBusiness = a.nameOfBusiness
        ) e
    )
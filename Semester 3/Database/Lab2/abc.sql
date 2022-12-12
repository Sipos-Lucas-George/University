use [Database];
-- a, b, c
-- UNION, OR

SELECT a.nameOfBusiness, a.fullName
FROM Administrator a
UNION
SELECT e.nameOfBusiness, e.fullName
FROM Employee e
ORDER BY nameOfBusiness DESC

SELECT TOP 2 a.nameOfBusiness, a.fullName, e.nameOfBusiness, e.fullName
FROM Administrator a, Employee e
WHERE a.nameOfBusiness = e.nameOfBusiness OR a.fullName = e.fullName
ORDER BY a.nameOfBusiness DESC, a.fullName

-- INTERSECT, IN

SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber
FROM Employee e
LEFT JOIN Load l
    ON e.fullName = l.employeeName
INTERSECT
SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber
FROM Employee e
RIGHT JOIN Administrator A
    ON A.nameOfBusiness = e.nameOfBusiness


SELECT TOP 2 *
FROM Load
WHERE loadID IN (
    SELECT companyID + 1
    FROM TransportExchange
    )
ORDER BY loadSupplierID

-- EXCEPT, NOT IN

SELECT *
FROM Load
EXCEPT
SELECT *
FROM Load
WHERE loadSupplierID IS NULL

SELECT *
FROM Load
WHERE loadID NOT IN (
    SELECT loadID * 2
    FROM LoadSupplier
    )

-- DISTINCT

SELECT COUNT(DISTINCT loadID) + COUNT(DISTINCT loadSupplierID)
FROM Load

SELECT DISTINCT wage, nameOfBusiness
FROM Employee

SELECT DISTINCT wage
FROM Employee

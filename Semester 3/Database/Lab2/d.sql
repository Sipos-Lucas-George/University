use [Database];
-- d
-- INNER JOIN, LEFT JOIN, RIGHT JOIN, FULL JOIN

SELECT a.nameOfBusiness, a.fullName, a.telephoneNumber, e.fullName, e.telephoneNumber, e.wage
FROM Administrator a
INNER JOIN Employee e
    ON a.nameOfBusiness = e.nameOfBusiness
ORDER BY nameOfBusiness DESC, wage DESC

SELECT l.loadID, l.employeeName, l.tripID, ls.nameOfCompany, ls.spokenLanguages
FROM Load l
LEFT JOIN LoadSupplier ls
    ON l.loadSupplierID = ls.loadID

SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber, l.loadSupplierID, t.*
FROM Employee e
INNER JOIN Load l
    ON e.fullName = l.employeeName
INNER JOIN LoadSupplier ls
    ON l.loadID = ls.loadID
RIGHT JOIN Trip T
    ON T.tripID = l.tripID

SELECT l.loadID, l.employeeName, t.loadingPoint, t.unloadingPoint, t.distance, t.price
FROM Load l
FULL JOIN Trip t
    ON l.tripID = t.tripID
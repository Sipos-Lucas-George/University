use [Database];
-- e
-- IN, NESTED IN

SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber, e.wage
FROM Employee e
WHERE e.wage IN (
    SELECT em.wage
    FROM Employee em
    WHERE em.fullName LIKE 'C% _%'
    )
EXCEPT
SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber, e.wage
FROM Employee e
WHERE e.fullName LIKE 'C% _%'

SELECT e.nameOfBusiness, e.fullName, e.telephoneNumber, e.wage
FROM Employee e
WHERE e.fullName IN (
    SELECT l.employeeName
    FROM Load l
    WHERE l.tripID IN (
        SELECT t.tripID
        FROM Trip t
        )
    )
ORDER BY e.nameOfBusiness DESC, e.wage DESC
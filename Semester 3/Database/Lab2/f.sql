use [Database];
-- f
-- EXISTS

SELECT *
FROM TransportBusiness b
WHERE EXISTS (
    SELECT *
    FROM Administrator a
    WHERE b.nameOfBusiness = a.nameOfBusiness AND EXISTS(
        SELECT *
        FROM Employee e
        WHERE a.nameOfBusiness = e.nameOfBusiness
        )
    )
ORDER BY b.nameOfBusiness DESC

SELECT *
FROM Employee e
WHERE EXISTS(
    SELECT *
    FROM Load l
    WHERE e.fullName = l.employeeName AND EXISTS(
        SELECT *
        FROM Trip t
        WHERE l.tripID = t.tripID
        )
    )
ORDER BY e.nameOfBusiness DESC, e.wage DESC
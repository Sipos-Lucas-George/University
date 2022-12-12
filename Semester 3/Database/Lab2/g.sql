use [Database];
-- g
-- FROM SUB-QUERY

SELECT *
FROM (
    SELECT *
    FROM Trip tr
    WHERE tr.price > 100
    ) t
WHERE (t.loadingPoint LIKE '[A-D]_' OR t.unloadingPoint LIKE '[A-D]_') AND t.distance < 400

SELECT *
FROM (
    SELECT l.loadID, l.employeeName, ls.nameOfCompany, ls.spokenLanguages
    FROM Load l
    LEFT JOIN LoadSupplier ls
        ON l.loadID = ls.loadID
    WHERE l.loadSupplierID IS NOT NULL
    ) la
WHERE la.spokenLanguages LIKE '_% _% _% _% _%'
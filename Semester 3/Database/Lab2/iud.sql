use [Database];

-- INSERT, UPDATE, DELETE

INSERT INTO TransportBusiness
    (nameOfBusiness, annualIncome, profitPercentage, establishedCompany)
VALUES
    ('West Gate Logistic SRL', 200000, 43.56, '2011-09-21'),
    ('Lucas & Andrei SLV SRL', 50000, 98, '2002-11-21'),
    ('Tara lui Andrei SRL', 25000, 20, '2002-09-03'),
    ('Cosmin FB GRS SRL', 10000, 10, '2000-01-01')

INSERT INTO Administrator
    (nameOfBusiness, fullName, telephoneNumber, officeAddress)
VALUES
    ('West Gate Logistic SRL', 'Sipos Constantin', '0780054201', 'Str. Alexandru Odobescu 420'),
    ('Lucas & Andrei SLV SRL', 'Sipos Lucks', '0780054202', 'Str. Alexandru Odobescu 420'),
    ('Tara lui Andrei SRL', 'Pop Andrei', '0780054203', 'Str. Marsillia 69'),
    ('Cosmin FB GRS SRL', 'Tomse Cosmin', '0780054204', 'Str. Alecu Russo 112')

INSERT INTO Employee
(nameOfBusiness, fullName, telephoneNumber, wage)
VALUES
    ('West Gate Logistic SRL', 'Ewald Fehrencz', '0712312300', 2100),
    ('West Gate Logistic SRL', 'Cosmin Fernea', '0712312301', 1800),
    ('Lucas & Andrei SLV SRL', 'Andrei Fabian', '0712312302', 100),
    ('Lucas & Andrei SLV SRL', 'Cosmin Vasile', '0712312303', 50),
    ('Tara lui Andrei SRL', 'Cosmin McBroom', '0712312303', 150),
    ('Tara lui Andrei SRL', 'Luca Dominique', '0712312304', 0),
    ('Cosmin FB GRS SRL', 'Cosmin Tomse', '0780054204', 100)

INSERT INTO Load
    (loadID, loadSupplierID, employeeName, tripID)
VALUES
    (1, 2, 'Ewald Fehrencz', 4),
    (2, 1, 'Cosmin Fernea', 2),
    (3, 2, 'Andrei Fabian', NULL),
    (4, 3, 'Cosmin Vasile', 1),
    (5, 4, 'Cosmin McBroom', NULL),
    (6, NULL, 'Luca Dominique', NULL),
    (7, NULL, 'Cosmin Tomse', NULL)

INSERT INTO LoadSupplier
    (nameOfCompany, telephoneNumber, spokenLanguages, loadID)
VALUES
    ('Coca Cola', '0760640000', 'English Spanish German Italian French', 1),
    ('Bugatti', '0760640001', 'English Spanish German Italian French Mandarin', 2),
    ('Napolact', '0760640002', 'Romanian English', 3),
    ('Fesh', '0760640003', 'English German French', 4)

INSERT INTO TransportExchange
    (siteLink, companyID)
VALUES
    ('www.timocom.ro', 1),
    ('www.timocom.ro', 2),
    ('www.timocom.ro', 3),
    ('www.timocom.ro', 4)

INSERT INTO Trip
    (tripID, loadingPoint, unloadingPoint, distance, price)
VALUES
    (1, 'SM', 'BM', 60, 100),
    (2, 'SM', 'BH', 130, 230),
    (3, 'TM', 'BN', 400, 600),
    (4, 'CT', 'DJ', 800, 2000),
    (5, 'AR', 'GJ', 350, 550)

UPDATE TransportBusiness SET profitPercentage = 0 WHERE profitPercentage = 20
UPDATE Administrator SET fullName = 'Sipos Lucas' WHERE fullName = 'Sipos Lucks' AND nameOfBusiness = 'Lucas & Andrei SLV SRL'
UPDATE Employee SET wage = 50 WHERE wage > 149 AND wage < 151

DELETE FROM Trip WHERE loadingPoint = 'SM' AND distance < 100
DELETE FROM Trip WHERE NOT price < 500

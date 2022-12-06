-- A
-- modify type of column
CREATE OR ALTER PROCEDURE setTransportSupplierToTinyInt AS
    ALTER TABLE TransportExchange ALTER COLUMN siteLink VARCHAR(1024)
go

CREATE OR ALTER PROCEDURE setTransportSupplierToInt AS
    ALTER TABLE TransportExchange ALTER COLUMN siteLink VARCHAR(256)
go
-- B
-- add/remove a column
CREATE OR ALTER PROCEDURE addCountryToLoadSupplier AS
    ALTER TABLE LoadSupplier ADD country VARCHAR(30)
go

CREATE OR ALTER PROCEDURE removeCountryToLoadSupplier AS
    ALTER TABLE LoadSupplier DROP COLUMN country
go

-- C
-- add/remove a default constraint
CREATE OR ALTER PROCEDURE addDefaultConstraintLoadSupplier AS
    ALTER TABLE LoadSupplier ADD CONSTRAINT DEFAULT0 DEFAULT('None') for country
go

CREATE OR ALTER PROCEDURE removeDefaultConstraintLoadSupplier AS
    ALTER TABLE LoadSupplier DROP CONSTRAINT DEFAULT0
go

-- G
CREATE OR ALTER PROCEDURE addSecondDriver AS
    CREATE TABLE SecondDriver (
        fullName VARCHAR(60) NOT NULL,
        sk VARCHAR(30) NOT NULL,
        tripID INT NOT NULL,
        CONSTRAINT USELESS_TABLE_PK PRIMARY KEY (fullName)
    )
go

CREATE OR ALTER PROCEDURE removeSecondDriver AS
    DROP TABLE SecondDriver
go

-- D
-- add/remove a primary key
CREATE OR ALTER PROCEDURE addSKasPK AS
    ALTER TABLE SecondDriver DROP CONSTRAINT IF EXISTS USELESS_TABLE_PK
    ALTER TABLE SecondDriver ADD CONSTRAINT USELESS_TABLE_PK PRIMARY KEY (fullName, sk)
go

CREATE OR ALTER PROCEDURE removeSKasPK AS
    ALTER TABLE SecondDriver DROP CONSTRAINT IF EXISTS USELESS_TABLE_PK
    ALTER TABLE SecondDriver ADD CONSTRAINT USELESS_TABLE_PK PRIMARY KEY (fullName)
go

-- E
-- add/remove candidate key
CREATE PROCEDURE addCandidateKey AS
    ALTER TABLE SecondDriver ADD CONSTRAINT USELESS_CANDIDATE_KEY UNIQUE (num)
go

CREATE OR ALTER PROCEDURE removeCandidateKey AS
    ALTER TABLE SecondDriver DROP CONSTRAINT IF EXISTS USELESS_CANDIDATE_KEY
go

-- F
-- add/remove foreign key
CREATE PROCEDURE addForeignKey AS
    ALTER TABLE SecondDriver ADD CONSTRAINT USELESS_FOREIGN_KEY FOREIGN KEY (num) REFERENCES Trip(tripID)
go

CREATE OR ALTER PROCEDURE removeForeignKey AS
    ALTER TABLE SecondDriver DROP CONSTRAINT IF EXISTS USELESS_FOREIGN_KEY
go

-- VERSION CONTROL
CREATE TABLE versionTable (
    version INT
)
go

INSERT INTO versionTable VALUES (1) -- INITIAL VERSION

CREATE TABLE proceduresTable (
    fromVersion INT,
    toVersion INT,
    PRIMARY KEY (fromVersion, toVersion),
    nameProcedure VARCHAR(MAX)
)
go

INSERT INTO proceduresTable
    (fromVersion, toVersion, nameProcedure)
VALUES
    (1, 2, 'setTransportSupplierToTinyInt'),
    (2, 1, 'setTransportSupplierToInt'),
    (2, 3, 'addCountryToLoadSupplier'),
    (3, 2, 'removeCountryToLoadSupplier'),
    (3, 4, 'addDefaultConstraintLoadSupplier'),
    (4, 3, 'removeDefaultConstraintLoadSupplier'),
    (4, 5, 'addSecondDriver'),
    (5, 4, 'removeSecondDriver'),
    (5, 6, 'addSKasPK'),
    (6, 5, 'removeSKasPK'),
    (6, 7, 'addCandidateKey'),
    (7, 6, 'removeCandidateKey'),
    (7, 8, 'addForeignKey'),
    (8, 7, 'removeForeignKey');

CREATE OR ALTER PROCEDURE toVersion(@newVersion INT) AS
    DECLARE @curr INT
    DECLARE @var VARCHAR(MAX)
    SELECT @curr = version
    FROM versionTable

    IF @newVersion > (SELECT MAX(toVersion)
                      FROM proceduresTable)
        raiserror ('BAD VERSION', 10, 1)

    IF @newVersion < (SELECT MIN(toVersion)
                      FROM proceduresTable)
        raiserror ('BAD VERSION', 10, 1)

    WHILE @curr > @newVersion
        BEGIN
            SELECT @var=nameProcedure FROM proceduresTable WHERE fromVersion=@curr AND toVersion=@curr - 1
            EXEC (@var)
            SET @curr = @curr - 1
        END

    WHILE @curr < @newVersion
        BEGIN
            SELECT @var=nameProcedure FROM proceduresTable WHERE fromVersion=@curr AND toVersion=@curr + 1
            EXEC (@var)
            SET @curr = @curr + 1
        END

    UPDATE versionTable SET version = @newVersion
go

EXEC toVersion @newVersion = 1
use [Database];

-- drop table if exists TransportBusiness
-- drop table if exists Employee
-- drop table if exists Trip
-- drop table if exists Load
-- drop table if exists LoadSupplier
-- drop table if exists TransportExchange
-- drop table if exists Route
-- drop table if exists Expenses
-- drop table if exists CMR

CREATE TABLE TransportBusiness
(
    nameOfBusiness     varchar(50) NOT NULL UNIQUE,
    annualIncome       float       NOT NULL,
    profitPercentage   float       NOT NULL,
    establishedCompany date,
    PRIMARY KEY (nameOfBusiness)
);

CREATE TABLE Administrator
(
    nameOfBusiness  varchar(50) FOREIGN Key REFERENCES TransportBusiness (nameOfBusiness) ON DELETE CASCADE,
    fullName        varchar(60)  NOT NULL,
    telephoneNumber varchar(15)  NOT NULL,
    officeAddress   varchar(100) NOT NULL,
    PRIMARY KEY (nameOfBusiness)
);

CREATE TABLE Employee
(
    nameOfBusiness  varchar(50) FOREIGN Key REFERENCES Administrator (nameOfBusiness) ON DELETE CASCADE,
    fullName        varchar(60) NOT NULL,
    telephoneNumber varchar(15) NOT NULL,
    wage            int         NOT NULL,
    PRIMARY KEY (fullName)
);

CREATE TABLE Trip
(
    tripID         int         NOT NULL,
    loadingPoint   varchar(60) NOT NULL,
    unloadingPoint varchar(60) NOT NULL,
    distance       int         NOT NULL,
    price          float,
    PRIMARY KEY (tripID)
);

CREATE TABLE Load
(
    loadID         int NOT NULL,
    loadSupplierID int,
    employeeName   varchar(60),
    tripID         int,
    PRIMARY KEY (loadID),
    FOREIGN KEY (loadSupplierID)
        REFERENCES Load (loadID)
        ON DELETE NO ACTION,
    FOREIGN KEY (employeeName)
        REFERENCES Employee (fullName)
        ON DELETE NO ACTION,
    FOREIGN KEY (tripID)
        REFERENCES Trip (tripID)
        ON DELETE NO ACTION
);

CREATE TABLE LoadSupplier
(
    loadID          int          NOT NULL,
    nameOfCompany   varchar(60)  NOT NULL,
    telephoneNumber varchar(15)  NOT NULL,
    spokenLanguages varchar(256) NOT NULL,
    primary key (loadID)
);

CREATE TABLE TransportExchange
(
    siteLink  varchar(256) NOT NULL,
    companyID INT          NOT NULL,
    FOREIGN KEY (companyID)
        REFERENCES LoadSupplier (loadID)
        ON DELETE CASCADE
);

CREATE TABLE Route
(
    routeID         int         NOT NULL,
    currentLocation varchar(60) NOT NULL,
    bestWayToGo     varchar(60) NOT NULL,
    FOREIGN KEY (routeID)
        REFERENCES Trip (tripID)
        ON DELETE CASCADE
);

CREATE TABLE Expenses
(
    routeID          int   NOT NULL,
    fuelPrice        float NOT NULL,
    employeeExpenses float NOT NULL,
    routeCost        float NOT NULL,
    FOREIGN KEY (routeID)
        REFERENCES Trip (tripID)
        ON DELETE CASCADE
);

CREATE TABLE CMR
(
    consignor    varchar(50) NOT NULL,
    loadSupplier INT NOT NULL,
    details      varchar(1024),
    FOREIGN KEY (consignor)
        REFERENCES Administrator (nameOfBusiness)
        ON DELETE CASCADE,
    FOREIGN KEY (loadSupplier)
        REFERENCES LoadSupplier (loadID)
);

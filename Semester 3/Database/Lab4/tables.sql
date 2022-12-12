use [Database];

create table Tables (
    tableID int primary key identity(1, 1),
    Name varchar(50)
)

create table Tests (
    testID int primary key identity(1, 1),
    Name varchar(50)
)

create table Views (
    viewID int primary key identity(1, 1),
    Name varchar(50)
)

create table TestTables (
    testID int,
    tableID int,
    noRows int,
    position int
)

create table TestViews (
    testID int,
    viewID int
)

create table TestRuns (
    runID int identity (1, 1),
    description varchar(256),
    startAt datetime2,
    endAt datetime2
)

create table TestRunTables (
    testRunID int,
    tableID int,
    startAt datetime2,
    endAt datetime2
)

create table TestRunViews (
    testRunID int,
    viewID int,
    startAt datetime2,
    endAt datetime2
)
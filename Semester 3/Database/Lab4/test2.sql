use [Database];

exec addToTables @tableName = 'Administrator'
exec addToTables @tableName = 'TransportBusiness'

create or alter view getCompaniesWithBigPercentage as
    select A.nameOfBusiness, T.profitPercentage
    from Administrator A full join TransportBusiness T on T.nameOfBusiness = A.nameOfBusiness
    where T.profitPercentage > 40
go

exec addToViews @viewName = 'getCompaniesWithBigPercentage'
exec addToTests @testName = 'test2'
exec connectTableToTest @tableName = 'Administrator', @testName = 'test2', @rows = 1000, @pos = 11
exec connectTableToTest @tableName = 'TransportBusiness', @testName = 'test2', @rows = 1000, @pos = 10
exec connectViewToTest @viewName = 'getCompaniesWithBigPercentage', @testName = 'test2'

create or alter procedure populateTableTransportBusiness (@rows int) as
    while @rows > 0 begin
        insert into TransportBusiness
            (nameOfBusiness, annualIncome, profitPercentage, establishedCompany)
        values
            (str(@rows), floor(rand()*999899999 + 100000), floor(rand()*100), '2002-11-21')
        set @rows = @rows - 1
    end
go

create or alter procedure populateTableAdministrator (@rows int) as
    while @rows > 0 begin
        insert into Administrator
            (nameOfBusiness, fullName, telephoneNumber, officeAddress)
        values
            (str(@rows), 'unknown', replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''), 'unknown')
        set @rows = @rows - 1
    end
go

exec runTest @testName = 'test2'
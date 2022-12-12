use [Database];

exec addToTables @tableName = 'Employee'

create or alter view getEmployeeAndAdministrators as
    select E.fullName, E.telephoneNumber, A.fullName as Boss, E.nameOfBusiness, E.wage
    from Employee E
    full join Administrator A on E.nameOfBusiness = A.nameOfBusiness
    group by E.fullName, E.telephoneNumber, A.fullName, E.nameOfBusiness, E.wage
go

exec addToViews @viewName = 'getEmployeeAndAdministrators'
exec addToTests @testName = 'test3'
exec connectTableToTest @tableName = 'Employee', @testName = 'test3', @rows = '1000', @pos = 20
exec connectTableToTest @tableName = 'Administrator', @testName = 'test3', @rows = '1000', @pos = 21
exec connectViewToTest @viewName = 'getEmployeeAndAdministrators', @testName = 'test3'

create or alter procedure populateTableEmployee (@rows int) as
    while @rows > 0 begin
        insert into Employee
            (nameOfBusiness, fullName, telephoneNumber, wage)
        values
            (str(@rows), replace(concat('Test', str(floor(rand()*89 + 10))), ' ', ''), replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''), floor(rand()*99999 + 1000))
        set @rows = @rows - 1
    end
go

create or alter procedure populateTableAdministrator (@rows int) as
    while @rows > 0 begin
        insert into Administrator
            (nameOfBusiness, fullName, telephoneNumber, officeAddress)
        values
            (str(@rows), replace(concat('Test', str(floor(rand()*899 + 1000))), ' ', ''), replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''), 'Unknown')
        set @rows = @rows - 1
    end
go

exec runTest @testName = 'test3'
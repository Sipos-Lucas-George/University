use [Database];

exec addToTables @tableName = 'LoadSupplier'

create or alter view getLoadSupplierTelephoneNumber as
    select telephoneNumber, count(*) as nr_of_telephoneNumber
    from LoadSupplier
    group by telephoneNumber
go

exec addToViews @viewName = 'getLoadSupplierTelephoneNumber'
exec addToTests @testName = 'test1'
exec connectTableToTest @tableName = 'LoadSupplier', @testName = 'test1', @rows = 1000, @pos = 5
exec connectViewToTest @viewName = 'getLoadSupplierTelephoneNumber', @testName = 'test1'

create or alter procedure populateTableLoadSupplier (@rows int) as
    while @rows > 0 begin
        insert into LoadSupplier
            (loadID, nameOfCompany, telephoneNumber, spokenLanguages)
        values
            (@rows, 'Testing', replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''), 'Unknown')
        set @rows = @rows - 1
    end
go

exec runTest @testName = 'test1'
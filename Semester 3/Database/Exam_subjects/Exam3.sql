use examn;

create table a (
    id int,
    c1 varchar(10),
    c2 int
)
create table z (
    id int,
    c1 varchar(10),
    c2 int
)
DROP TABLE z
insert into a
values
    (1,'A',10),
    (2,'B',5),
    (3,'C',30),
    (4,'A',24),
    (9,'B',11),
    (2,'C',2),
    (10,'B',0)

insert into z
values
    (6,'A',4),
    (2,'B',54),
    (3,'C',0),
    (7,'A',43),
    (4,'B',12),
    (8,'C',13),
    (5,'B',32)

select
    sum(case when aid is not null and zid is null then 1 else 0 end) f1,
    sum(case when zid is not null and aid is null then 1 else 0 end) f2,
    sum(case when zid is not null and aid is not null then 1 else 0 end) f3
from (
    select distinct a.id as aid, z2.id as zid
    from a
    left join z z2 on a.id = z2.id
     ) t

create or alter trigger trigg on z for update
as
    declare @n int = 0
    select @n = @n + abs(i.c2 - d.c2)
    from deleted d
    inner join inserted i on d.id = i.id
    print @n
go

update z set c2 = 10 where id+c2 > 25


create table coffeeShops (
    id int primary key identity (1, 1),
    suid int foreign key references suppliers(id),
    cname varchar(100) unique,
    city varchar(100)
)
create table employees (
    id int primary key identity (1, 1),
    cid int foreign key references coffeeShops(id),
    fname varchar(100),
    lname varchar(100),
    jtitle varchar(100),
    hdate date
)
create table coffees (
    id int primary key identity (1, 1),
    cid int foreign key references coffeeShops(id),
    suid int foreign key references suppliers(id),
    cname varchar(100),
    price int
)
create table suppliers (
    id int primary key identity (1, 1),
    sname varchar(100),
    country varchar(100),
    email varchar(100)
)

insert into suppliers
values
    ('A', 'R', 'email@hotmail.com'),
    ('B', 'R', 'email@hotmail.com'),
    ('C', 'R', 'email@hotmail.com'),
    ('D', 'R', 'email@hotmail.com'),
    ('E', 'R', 'email@hotmail.com'),
    ('F', 'R', 'email@hotmail.com'),
    ('G', 'R', 'email@hotmail.com')
insert into coffeeShops
values
    (3, 'Singing Beans', 'rr'),
    (1, 'AA', 'RR'),
    (2, 'BB', 'RR'),
    (3, 'CC', 'RR'),
    (4, 'DD', 'RR'),
    (5, 'EE', 'RR'),
    (6, 'FF', 'RR'),
    (7, 'GG', 'RR'),
insert into coffees
values
    (3, 1, 'AAA', 10),
    (3, 1, 'BBB', 20),
    (3, 1, 'CCC', 30),
    (4, 1, 'DDD', 40),
    (4, 2, 'EEE', 50),
    (4, 2, 'FFF', 60),
    (5, 4, 'GGG', 70)
go
insert into employees
values
    (3, 'a', 'aa', 'employee', '01-02-2020'),
    (3, 'b', 'bb', 'employee', '01-02-2021'),
    (3, 'c', 'cc', 'employee', '01-02-2022'),
    (4, 'd', 'dd', 'employee', '01-02-2019'),
    (4, 'e', 'ee', 'employee', '11-12-2021'),
    (4, 'f', 'ff', 'employee', '01-02-2020')

create or alter procedure addResult (@cname varchar(100), @price int) as
    declare @cid int = (select coffeeShops.id from coffeeShops where coffeeShops.cname like 'Singing Beans')
    declare @suid int = (select t.id
                        from (select top 1 count(*) as cnt, s.id
                         from suppliers s
                         left join coffees c on s.id = c.suid
                         group by s.sname, s.id
                         ) t
                        )
    insert into coffees values (@cid, @suid, @cname, @price)
go


addResult @cname = 'Old', @price = 170

create or alter view mostExp as
    select top 3 s.country
    from coffees c
    inner join suppliers s on s.id = c.suid
    order by c.price
go

create or alter function fullNameMoreX (@x int)
returns table
as
    return (select concat(e.fname, e.lname) as fullName
            from employees e
            where datediff(year, e.hdate, getdate()) > 2
            )

exec fullNameMoreX @x = 2
select fullNameMoreX(2)
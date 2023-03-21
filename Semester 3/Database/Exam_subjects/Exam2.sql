use Test

create table A
(
    FK1 int,
    FK2 int,
    C1  varchar(256),
    C2  varchar(256),
    C3  int,
    C4  int,
    C5  int
)

insert into A (FK1, FK2, C1, C2, C3, C4, C5)
values (1, 1, null, 'g', 5, 7, 58),
       (1, 2, null, 'f', 2, 4, 21),
       (1, 3, null, 'd', 3, 1, 48),
       (1, 4, null, 'f', 2, 16, 21),
       (2, 1, null, 'd', 4, 1, 47),
       (2, 2, null, 'g', 5, 9, 52),
       (2, 3, null, 'd', 3, 1, 47),
       (3, 1, null, 's', 5, 8, 23),
       (3, 2, null, 'g', 3, 9, 50),
       (3, 3, null, 's', 5, 5, 23),
       (3, 4, null, 'd', 6, 5, 48),
       (4, 1, null, 's', 3, 5, 24),
       (4, 2, null, 'g', 2, 1, 51),
       (4, 3, null, 'f', 2, 21, 26)

select C2, AVG(C5) avg5, Sum(C3) sumC3C4
from A
Where C3 > 2
GROUP BY C2
HAVING COUNT(*) > 1

select *
from (select FK1, FK2, C5 + C3 sumC3C5
      from A
      where FK1 = FK2) r1
         inner join (Select FK1, FK2, C5
                     FROM A
                     WHERE C3 > 5) r2 on r1.FK1 = r2.FK1 and r1.FK2 = r2.FK2

-- 1 1 63
-- 2 2 57
-- 3 3 28

-- 3 4 48


create or alter trigger tryU
    on A
    for update
    as
begin
    declare @total int=0
    select @total = sum(i.C4 + d.C4)
    from deleted d
             inner join inserted i on d.FK1 = i.FK1 and d.FK2 = i.FK2
    where d.C4 < i.C4
    print @total
end
go

update A
set C5 = 50
where FK1 > FK2
go

create table Countries
(
    id    int primary key identity (1, 1),
    cname varchar(50),
)

create table Athletes
(
    id    int primary key identity (1, 1),
    aname varchar(50),
    cname int references Countries (id),
    bday  varchar(20),
)

create table Sports
(
    id    int primary key identity (1, 1),
    sname varchar(50),
)

create table SportEvents
(
    id      int primary key identity (1, 1),
    sname   int references Sports (id),
    details varchar(200),
)

create table Venues
(
    id       int primary key identity (1, 1),
    vaddress varchar(100),
    city     varchar(100)
)

create table Results
(
    id      int primary key identity (1, 1),
    athlete int references Athletes (id),
    sportE  int references SportEvents (id),
    rdate   varchar(20),
    rrank   int,
    details varchar(10),
    constraint details_value check (details like 'PB' OR details like 'WR' OR details like 'OR' OR details like 'N/A' OR
                                    details is null)
)

create or alter procedure addResult (@ath int, @sE int, @rk int, @rt varchar(10), @dt varchar(50)) as
    if exists(select athlete, sportE from Results where athlete = @ath and sportE = @sE) begin
        update Results set rrank = @rk where athlete = @ath and sportE = @sE
        update Results set rdate = @dt where athlete = @ath and sportE = @sE
        update Results set details = @rt where athlete = @ath and sportE = @sE
        return
    end
    insert into Results (athlete, sportE, rdate, rrank, details) values (@ath, @sE, @dt, @rk, @rt)
go
insert into Countries values ('R')
insert into Countries values ('I')
insert into Athletes values ('L',2,'1121')
insert into Athletes values ('A',1,'6969')
insert into Athletes values ('C',1,'3213')
insert into Sports values ('ODF')
insert into Sports values ('JUDO')
insert into Sports values ('CROSS')
insert into SportEvents values (1,'100p in m')
insert into SportEvents values (2,'1 ipon freestyle')
insert into SportEvents values (3,'50 balls freestyle')
insert into SportEvents values (2,'2 ipon/2 freestyle')
insert into Venues values ('Titu','SM')
insert into Venues values ('Choco Avenue','Tokyo')
go
addResult @ath = 2, @sE = 2, @rk = 1, @rt = 'PB', @dt = '1691';
addResult @ath = 1, @sE = 2, @rk = 1, @rt = 'OR', @dt = '2102';
addResult @ath = 1, @sE = 4, @rk = 1, @rt = 'OR', @dt = '2102';
addResult @ath = 3, @sE = 4, @rk = 3, @rt = 'OR', @dt = '1111';

create or alter view showJudoAthletes as
    select a.aname
    from Athletes a
    where a.id in (
        select r.athlete
        from SportEvents ses
        inner join Results r on ses.id = r.sportE
        where ses.sname in (select id
                            from Sports
                            where Sports.sname like 'JUDO'
                            )
    )
go

create or alter function moreGoldMedals (@r int, @s varchar(50))
returns int
as
    begin
    declare @c int
    set @c = (select count(*) as cnt
              from (select r.athlete
                    from SportEvents ses
                             inner join Results r on ses.id = r.sportE
                    where ses.sname in (select id
                                        from Sports
                                        where Sports.sname like @s)
                      and r.rrank = 1
                    group by r.athlete
                    having count(*) > @r) ta
              )
    return @c
end

declare @res int
exec @res = moreGoldMedals @r = 1, @s = 'JUDO'
print @res
-- exec moreGoldMedals @r = 0, @s = 2
-- select moreGoldMedals(0,2)

create table Client
(
    id        int primary key auto_increment,
    full_name varchar(100),
    telephone varchar(15)
);

create table Room
(
    id       int primary key auto_increment,
    category varchar(50),
    type     varchar(50),
    price    int,
    hotel_id int,
    foreign key (hotel_id) references Hotel (id)
);

create table Hotel
(
    id       int primary key auto_increment,
    name     varchar(100),
    location varchar(100)
);

create table Reservation
(
    id        int primary key auto_increment,
    client_id int,
    room_id   int,
    checkin   datetime not null,
    checkout  datetime not null,
    foreign key (client_id) references Client (id),
    foreign key (room_id) references Room (id)
);
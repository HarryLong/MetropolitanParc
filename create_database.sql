create table users
( 
  passcode bigint unsigned not null primary key,
  name char(50) not null,
  download_count TINYINT(20)
);

/*
   select * from waypoints
   select * from groups
   insert into groups(name) values ('Sardegna')

   see schema
  SELECT * FROM sqlite_master;

  CREATE TABLE groups
  ( id INTEGER PRIMARY KEY AUTOINCREMENT,
  name VARCHAR NOT NULL,
  description VARCHAR
  );


   insert into waypoints(lat,lon,alt,name,type,groups) values (52.5088746,-13.3733143,0,'Ufficio',2,1);

   ALTER TABLE waypoints ADD groups int;







*/

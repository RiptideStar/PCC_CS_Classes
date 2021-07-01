use MyStore;

INSERT INTO Stock (Sku, Name, Description, Price)
    VALUES (4, 'Huge Dunk Tank', 'Very Wet and Slippery Game', 800.99);

INSERT INTO Stock (Sku, Name, Description, Price)
    VALUES (5, 'Controller', 'General Video Game Input', 24.99);

CREATE TABLE Customer (
    CustomerId int,
    FirstName varchar(64),
    LastName varchar(64),
    Email varchar(64),
    Address varchar(64),
    City varchar(64),
    StateProvence varchar(64),
    Country varchar(64)
);

INSERT INTO Customer (CustomerId, FirstName, LastName, Email, Address, City, StateProvence, Country)
VALUES (1, 'Tyson', 'Ngo', 'tenz@gmail.com', '45 Ontario Street', 'Ottawa', 'Ontario', 'Canada');
INSERT INTO Customer (CustomerId, FirstName, LastName, Email, Address, City, StateProvence, Country)
VALUES (2, 'Tom', 'Yala', 'tyala@gmail.com', '56 Toronto Street', 'Toronto', 'Ontario', 'Canada');
INSERT INTO Customer (CustomerId, FirstName, LastName, Email, Address, City, StateProvence, Country)
VALUES (3, 'Tommy', 'Polo', 'tpolo@gmail.com', '56 Toronto Street', 'Toronto', 'Ontario', 'Canada');
INSERT INTO Customer (CustomerId, FirstName, LastName, Email, Address, City, StateProvence, Country)
VALUES (4, 'Mariano', 'Arruda', 'marruda@gmail.com', '45 Ontario Street', 'Ottawa', 'Ontario', 'Canada');
INSERT INTO Customer (CustomerId, FirstName, LastName, Email, Address, City, StateProvence, Country)
VALUES (5, 'Matthew', 'Yarckun', 'clover@gmail.com', 'MLK Street', 'Portland', 'Oregon', 'USA');


SELECT * FROM Customer;
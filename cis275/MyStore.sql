-- Just about every command except for use and SELECT can only be run once without error.  To avoid this
-- either comment out the lines already run or select a section of code then press run

-- Create the database.  These lines should be executed separately since 
-- they must complete before the rest of the commands can be run
use master;
create database MyStore;

-- When above completes, then select the rest of the commands below and click run.

-- must tell SQL Server which database to use
use MyStore;

-- Simple Table Creation.  Note lack of keys or constraints.  We'll add those later
-- Note use of decimal instead of a floating point for avoiding round-off error
-- in financial calculations

CREATE TABLE Stock (
    Sku int,
    Name varchar(64),
    Description varchar(64),
    Price decimal(6,2) -- can represent values up to 9999.99
);

-- Insert some items into stock, like above commands can only be executed once.
INSERT INTO Stock (Sku, Name, Description, Price)
    VALUES (1, 'Widget', 'Non-descript component', 3.99);

INSERT INTO Stock (Sku, Name, Description, Price)
    VALUES (1, 'Cog', 'A generic part of a bigger system', 1.99);

INSERT INTO Stock (Sku, Name, Description, Price)
    VALUES (1, 'Rocket Powered Roller Skates'
    , 'What every coyote needs to catch that road runner', 599.99);



-- view the items inserted.  This command can always be run if Stock exists.
SELECT * FROM Stock;


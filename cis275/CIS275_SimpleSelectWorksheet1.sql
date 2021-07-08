

USE FiredUp    -- ensures correct database is active

GO
PRINT 'CIS2275, Lab1, question 1, ten points possible.
Project everything (all columns and all rows) from the SUPPLIERS table.' + CHAR(10)
-- Your SELECT will have a list of column names each separated with a comma (,).
-- Each projection item goes on a separate line. Do not format output nor use aliases.
-- Your FROM will name the table and end with a semi-colon (;).
SELECT 
    SupplierNbr, 
    Name,
    SalesRep,
    RepPhoneNumber, 
    CSPhoneNumber, 
    Address, 
    City, 
    State
FROM SUPPLIER;
GO

-- Example of query
SELECT 
    SupplierNbr
    , Name
    , SalesRep
    , RepPhoneNumber
    , CSPhoneNumber
    , Address
    , City
    , State
FROM Supplier;

GO
PRINT 'CIS275, Lab1, question 2, ten points possible.
Project everything (all columns and all rows) from the STOVE table.' + CHAR(10);
-- Your SELECT will have a list of column names each separated with a comma (,).
-- Each projection item goes on a separate line. Do not format output nor use aliases.
-- Your FROM will name the table and end with a semi-colon (;).
SELECT 
    SerialNumber,
    Type,
    Version,
    DateOfManufacture,
    Color,
    FK_EmpId
FROM STOVE;
GO



GO
PRINT REPLICATE('=',80) + CHAR(10) +
'From now on all columns projecting in the SELECT clause must be named.  Do not
use * except when developing queries.  Dates numbers that are currency (money)
must be explicitly formatted using one of the following.
Formats to use are the following:

CAST(column_name AS CHAR(#)) for character data where # is field length
STR(column_name, precision, scale) for numbers 
    where precision is field length and includes the decimal point 
    and scale is the number of decimal places (always use 2 for money)
CONVERT(CHAR(12), column_name, #) for dates where # is 1 or 101

Use the first to shorten strings.  Although you can leave most strings in their
current length, you shorten strings, expecially when the output overflows to the next line
' + 
CHAR(10) +REPLICATE('=',80) + CHAR(10);
GO
PRINT 'CIS275, Lab1, question 3, ten points possible.
Display everything from the PURCHASE_ORDER table.' + CHAR(10);
SELECT 
    PONbr,
    OrderDt,
    Terms,
    FK_SupplierNbr
FROM PURCHASE_ORDER;    
GO



GO
PRINT 'CIS275, Lab1, question 4, ten points possible.
You have been asked to supply a list of all employees names
and their ID numbers. Do so.' + CHAR(10);
SELECT
    EmpID,
    Name
FROM EMPLOYEE;
GO



GO
PRINT 'CIS275, Lab1, question 5, ten points possible.
Show the FK_PartNbr, Quantity, ExtendedPrice and (ExtendedPrice * 1.07) from the
REPAIR_LINE_ITEM table. Limit output to rows have a quantity greater than one.' + CHAR(10);
SELECT 
    FK_PartNbr,
    Quantity,
    STR(ExtendedPrice, 6, 2) AS ExtendedPrice,
    (ExtendedPrice * 1.07) AS ExtendedPrice_Multiplied_By_1_07
FROM REPAIR_LINE_ITEM
WHERE Quantity > 1;
GO



GO
PRINT 'CIS2275, Lab1, question 6, ten points possible.
What INVOICEs have TotalPrice of more than $200? 
Show InvoiceNbr, InvoiceDt, and TotalPrice.' + CHAR(10)
SELECT 
    InvoiceNbr,
    InvoiceDt,
    TotalPrice
FROM INVOICE
WHERE TotalPrice > 200;
GO



GO
PRINT 'CIS275, Lab1, question 7, ten points possible.
What INVOICEs have TotalPrice of BETWEEN $1 AND $50? 
Show InvoiceNbr, InvoiceDt, and TotalPrice.' + CHAR(10);
SELECT 
    InvoiceNbr,
    InvoiceDt,
    TotalPrice
FROM INVOICE
WHERE TotalPrice BETWEEN 1 AND 50;
GO



GO
PRINT 'CIS275, Lab1, question 8, ten points possible.
Display FK_InvoiceNbr, LineNbr, FK_StoveNbr from the INV_LINE_ITEM table.
Eliminate non-stove rows: WHERE FK_PartNbr IS NULL.' + CHAR(10);
SELECT
    FK_InvoiceNbr,
    LineNbr,
    FK_StoveNbr
FROM INV_LINE_ITEM
WHERE FK_PartNbr IS NULL;
GO



GO
PRINT 'CIS275, Lab1, question 9, ten points possible.
Show all columns of PURCHASE_ORDER table 
WHERE FK_SupplierNbr IN (801, 803, 805, 807).' + CHAR(10);
SELECT 
    PONbr,
    OrderDt,
    Terms,
    FK_SupplierNbr
FROM PURCHASE_ORDER
WHERE FK_SupplierNbr IN (801, 803, 805, 807);
GO



GO
PRINT 'CIS275, Lab1, question 10, ten points possible.
Show all columns of PURCHASE_ORDER table 
WHERE FK_SupplierNbr NOT IN (801, 803, 805, 807).' + CHAR(10);
SELECT 
    PONbr,
    OrderDt,
    Terms,
    FK_SupplierNbr
FROM PURCHASE_ORDER
WHERE FK_SupplierNbr NOT IN (801, 803, 805, 807);


GO
-------------------------------------------------------------------------------------
-- This is an anonymous program block. DO NOT CHANGE OR DELETE.
-------------------------------------------------------------------------------------
BEGIN
    PRINT '|---' + REPLICATE('+----',15) + '|';
    PRINT ' End of CIS275 Lab1' + REPLICATE(' ',50) + CONVERT(CHAR(12),GETDATE(),101);
    PRINT '|---' + REPLICATE('+----',15) + '|';
END;



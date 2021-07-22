/*
CIS275 SQL Lab4
Kyle Zhang
7/21
7/22
8/2/2021 DUE DATE
*/

USE FiredUp    -- ensures correct database is active
--ALL PROJECTED QUERIES MUST BE FORMATTED AND ALIASED ACCORDING TO INSTRUCTIONS IN SQLLAB1:
PRINT REPLICATE('=',80) + CHAR(10) +
'From now on every query will have formatted projection items with aliases
and end with a semi-colon. Table names are uppercase.
Formats to use are the following:
CAST(column_name AS CHAR(#)) for character data where # is field length
STR(column_name, precision, scale) for numbers
    where precision is field length and includes the decimal point
    and scale is the number of decimal places (always use 2 for money)
CONVERT(CHAR(12), column_name, #) for dates where # is 1 or 101' +
CHAR(10) +REPLICATE('=',80) + CHAR(10);
GO


GO
PRINT 'CIS2275, Lab2, question 1, ten points possible.
Which customers (ID and name) have invoices? Sort on name descending.' + CHAR(10)
-- Selection criteria involves a subquery returning FK_CustomerID from INVOICE table.
SELECT Name, CustomerID FROM CUSTOMER
WHERE CustomerID IN (
SELECT FK_CustomerID FROM INVOICE)
ORDER BY Name DESC;
GO



GO
PRINT 'CIS275, Lab2, question 2, ten points possible.
What stove colors have been sold? Display SerialNumber and Color.
Results to be in ascending order of SerialNumber.' + CHAR(10);
-- Selection criteria involves subquery returning FK_StoveNbr from INV_LINE_ITEM table.
SELECT SerialNumber, Color FROM STOVE
WHERE SerialNumber IN
(SELECT FK_StoveNbr FROM INV_LINE_ITEM)
ORDER BY SerialNumber ASC;
GO



GO
PRINT 'CIS275, Lab2, question 3, ten points possible.
Project InvoiceNbr, InvoiceDt and TotalPrice for all invoices where the TotalPrice
is greater than the average TotalPrice. Sort on InvoiceNbr descending.' + CHAR(10);
-- Selection criteria is with subquery returning AVG(TotalPrice) from INVOICE.
SELECT InvoiceNbr, CONVERT(CHAR(12), InvoiceDt, 1) AS InvoiceDt, STR(TotalPrice, 8, 2) AS TotalPrice 
from INVOICE
WHERE TotalPrice >
(SELECT AVG(TotalPrice) from INVOICE)
ORDER BY InvoiceNbr DESC;
GO



GO
PRINT 'CIS275, Lab2, question 4, ten points possible.
Project InvoiceNbr, InvoiceDt and TotalPrice for the invoice or invoices
with the largest quantity line item. Sort on InvoiceNbr ascending.' + CHAR(10);
-- Selection criteria in the set of FK_InvoiceNbr FROM INV_LINE_ITEM having the 
-- selection criteria equal to the MAX(Quantity) FROM INV_LINE_ITEM.
SELECT InvoiceNbr, CONVERT(CHAR(12), InvoiceDt, 1) AS InvoiceDt, STR(TotalPrice, 8, 2) AS TotalPrice
from INVOICE
WHERE InvoiceNbr IN (
    SELECT FK_InvoiceNbr from INV_LINE_ITEM
    WHERE Quantity = (
        SELECT MAX(Quantity) FROM INV_LINE_ITEM
    )
)
ORDER BY InvoiceNbr ASC;
GO


GO
PRINT 'CIS275, Lab2, question 5, ten points possible.
Which customers have NOT brought in stoves for repair?
Display name and ID sorted on name ascending.' + CHAR(10);
-- Subquery returns FK_CustomerID FROM STOVE_REPAIR to use in selection criteria.
-- You can use either a correlated or non-correlated subquery.
SELECT Name, CustomerID FROM CUSTOMER
WHERE CustomerID NOT IN
(SELECT FK_CustomerID FROM STOVE_REPAIR)
ORDER BY Name ASC;
GO



GO
PRINT 'CIS2275, Lab2, question 6, ten points possible.
Which invoice(s) cover parts whose name contains either widget or whatsit? 
Show invoice number and date in order by date then invoice number.' + CHAR(10)
-- Selection criteria contains two subqueries one nested in the other;
-- that is, a subquery that itself contains a subquery.
-- Use LIKE and wildcards to return PartNbr from PART that is used in the
-- conditon for innermost subquery returning PartNbr that can be checked against FK_InvoiceNbr 
-- from INV_LINE_ITEM (in the outer subqueyr).
-- Condition in innermost subquery is compound w/one condition checking for PART.Description like widget
-- *OR* the second condition for PART.Description like whatsit
SELECT InvoiceNbr, CONVERT(CHAR(12), InvoiceDt, 1) AS InvoiceDt
FROM INVOICE
WHERE InvoiceNbr IN
(SELECT FK_InvoiceNbr FROM INV_LINE_ITEM 
WHERE FK_PartNbr IN
(SELECT PartNbr from PART
WHERE Description LIKE '%Widget%' OR Description LIKE '%Whatsit%')
)
ORDER BY InvoiceDt, InvoiceNbr;
GO

GO
PRINT 'CIS275, Lab2, question 7, ten points possible.
Project the invoice numbers containing FiredNow Stoves.' + CHAR(10);
-- Project DISTINCT FK_InvoiceNbr from INV_LINE_ITEM with condition
-- using non-correlated subquery returning SerialNumber of STOVEs that are 'FiredNow'.
SELECT DISTINCT FK_InvoiceNbr FROM INV_LINE_ITEM 
WHERE FK_StoveNbr IN
(SELECT SerialNumber FROM STOVE
WHERE Type = 'FiredNow');
GO



GO
PRINT 'CIS275, Lab2, question 8, ten points possible.
Project the invoice numbers containing FiredNow Stoves using EXISTS.' + CHAR(10);
-- Same as previous query except subquery must be correlated to use the EXISTS clause.
SELECT DISTINCT FK_InvoiceNbr FROM INV_LINE_ITEM 
WHERE EXISTS
(SELECT SerialNumber FROM STOVE
WHERE Type = 'FiredNow' and FK_StoveNbr = SerialNumber);
GO



GO
PRINT 'CIS275, Lab2, question 9, ten points possible.
Provide a list of the employees who build stoves. Use EXISTS properly.
Display employee name concatenated to title.' + CHAR(10);
-- Building a non-correlated subquery can be your test.
SELECT Name + ', ' + Title AS EmpName_Title
FROM EMPLOYEE
WHERE EXISTS
(SELECT FK_EmpID FROM STOVE WHERE FK_EmpID IS NOT NULL AND FK_EmpId = EmpID);

-- -- Non-correlated subquery test:
-- SELECT Name + ', ' + Title AS EmpName_Title
-- FROM EMPLOYEE
-- WHERE EmpID IN 
-- (SELECT FK_EmpID FROM STOVE);
GO



GO
PRINT 'CIS275, Lab2, question 10, ten points possible.
Which part has the second highest cost? Display PartNbr and Description' + CHAR(10);
-- Subquery returns the two highest cost parts using a sort and TOP 2 WITH TIES.
-- Final projection returns the highest cost part in the subquery and needs
-- a sort and TOP 1 WITH TIES.
SELECT TOP 1 WITH TIES T.PartNbr, T.Description
FROM (
    SELECT TOP 2 WITH TIES *
    FROM PART
    ORDER BY Cost DESC
) AS T
ORDER BY T.Cost ASC ---ascending will make the subquery be organized with the outer SELECT TOP 1 being the second highest cost :)
;

GO
-------------------------------------------------------------------------------------
-- This is an anonymous program block. DO NOT CHANGE OR DELETE.
-------------------------------------------------------------------------------------
BEGIN
    PRINT '|---' + REPLICATE('+----',15) + '|';
    PRINT ' End of CIS275 Lab2' + REPLICATE(' ',50) + CONVERT(CHAR(12),GETDATE(),101);
    PRINT '|---' + REPLICATE('+----',15) + '|';
END;



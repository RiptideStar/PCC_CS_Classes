/*
CIS275, SQLLab 3 questions 
PCC using Microsoft SQL Server 2008
Kyle Zhang
7/15/2021 - 7/17/2021
2021/07/26 DUE DATE
*/

/*
CAST(column_name AS CHAR(#)) for character data where # is field length
STR(column_name, precision, scale) for numbers 
    where precision is field length and includes the decimal point 
    and scale is the number of decimal places (always use 2 for money)
CONVERT(CHAR(12), column_name, #) for dates where # is 1 or 101
*/

USE FiredUp    -- ensures correct database is active
GO
PRINT 'Remember that money is always formatted to two decimal places.
The answer file will show both implicit and explicit joining. Unless
requested otherwise you may use either.' + CHAR(10);

GO
PRINT 'CIS2275, Lab3, question 1, ten points possible.
Perform an inner join of the CUSTOMER table to the INVOICE table (CUSTOMER.CustomerID = INVOICE.FK_CustomerID).
Show, format and alias each column of both tables. Please concatenate City, StateProvince ZipCode, Country' + CHAR(10)
SELECT Customer.CustomerID AS ID, Customer.Name, Customer.StreetAddress, Customer.ApartmentNbr,
    Customer.City + ', ' + Customer.StateProvince+', '+Customer.ZipCode+', '+Customer.Country AS Location,
    INVOICE.InvoiceNbr, CONVERT(CHAR(12), INVOICE.InvoiceDt, 1) AS InvoiceDt, STR(INVOICE.TotalPrice, 8, 2) AS TotalPrice,
    INVOICE.FK_EmpID
FROM Customer
INNER JOIN INVOICE ON CUSTOMER.CustomerID = INVOICE.FK_CustomerID;
GO


GO
PRINT 'CIS275, Lab3, question 2, ten points possible.
Perform an explicit full outer join of the CUSTOMER table to the INVOICE table. 
Display only the customer name, invoice number and invoice date.
SQL Server has no provision for implicit full outer joins.' + CHAR(10);
SELECT C.Name,  I.InvoiceNbr, CONVERT(CHAR(12), I.InvoiceDt, 1) AS InvoiceDt
FROM CUSTOMER C 
FULL OUTER JOIN INVOICE I ON C.CustomerID = I.FK_CustomerID;
GO


GO
PRINT 'CIS275, Lab3, question 3, ten points possible.
Join CUSTOMER table to INVOICE table to display customer name and invoice number 
for those customers with invoices. Restrict output to those customers having the 
last name of White. (Use LIKE keyword and wildcard)
Be careful: we don''t want to see Donna Penwhite in the output.' + CHAR(10);
SELECT C.Name, I.InvoiceNbr
FROM Customer C 
INNER JOIN Invoice I ON C.CustomerID = I.FK_CustomerID
WHERE I.InvoiceNbr IS NOT NULL AND C.Name LIKE '% White';
GO


GO
PRINT 'CIS275, Lab3, question 4, ten points possible.
Include INV_LINE_ITEM to the join from previous question to add 
line number, quantity, FK_PartNbr and FK_StoveNbr to output.' + CHAR(10);
SELECT C.Name, I.InvoiceNbr, IL.LineNbr, IL.Quantity, IL.FK_PartNbr, IL.FK_StoveNbr
FROM Invoice I
INNER JOIN Customer C ON C.CustomerID = I.FK_CustomerID
INNER JOIN INV_LINE_ITEM IL ON I.InvoiceNbr = IL.FK_InvoiceNbr
WHERE I.InvoiceNbr IS NOT NULL AND C.Name LIKE '% White';
GO


GO
PRINT 'CIS275, Lab3, question 5, ten points possible.
Include STOVE table to join in previous question.
Display customer name, invoice number, serialnumber, and extended price.
Remove restriction on CUSTOMER last name of White.
Restrict output to only rows containing stoves.' + CHAR(10);
SELECT C.Name, I.InvoiceNbr, STR(IL.ExtendedPrice, 8, 2) AS ExtendedPrice, S.SerialNumber
FROM Invoice I
INNER JOIN Customer C ON C.CustomerID = I.FK_CustomerID
INNER JOIN INV_LINE_ITEM IL ON I.InvoiceNbr = IL.FK_InvoiceNbr
INNER JOIN Stove S ON IL.FK_StoveNbr = S.SerialNumber
WHERE I.InvoiceNbr IS NOT NULL AND IL.FK_StoveNbr IS NOT NULL;
GO


GO
PRINT 'CIS2275, Lab3, question 6, ten points possible.
Project EMPLOYEE id and name, INVOICE number and total price using a LEFT OUTER JOIN
to show all employees whether they have sold anything or not.' + CHAR(10);
SELECT E.EmpID, E.Name, I.InvoiceNbr, STR(I.TotalPrice, 8, 2) AS TotalPrice
FROM EMPLOYEE E
LEFT OUTER JOIN INVOICE I ON I.FK_EmpID = E.EmpID;
GO


GO
PRINT 'CIS275, Lab3, question 7, ten points possible.
What is the average total price of invoices written by Fred Bailey? 
Display the number of invoices written by Fred
and the average total price of invoices.' + CHAR(10);
SELECT COUNT(E.Name) AS NumInvoices, STR(AVG(I.TotalPrice), 8, 2) AS AvgPrice
FROM INVOICE AS I
INNER JOIN EMPLOYEE AS E ON E.EmpID = I.FK_EmpID
WHERE E.Name = 'Fred Bailey';
GO


GO
PRINT 'CIS275, Lab3, question 8, ten points possible.
Display invoice number, invoice date, and stove number for all sold stoves. 
List in chronological order by invoice date.' + CHAR(10);
SELECT CONVERT(CHAR(12), I.InvoiceDt, 1) AS InvoiceDt, I.InvoiceNbr, IL.FK_StoveNbr
FROM INVOICE AS I
INNER JOIN INV_LINE_ITEM AS IL ON I.InvoiceNbr = IL.FK_InvoiceNbr
WHERE IL.FK_StoveNbr IS NOT NULL
ORDER BY I.InvoiceDt;
GO



GO
PRINT 'CIS275, Lab3, question 9, ten points possible.
Which stove invoices are in May of 2002? Display invoice number, 
invoice date, and stove number. Use BETWEEN to specify the date range 
and list in chronological order by invoice date.' + CHAR(10);
SELECT I.InvoiceNbr, CONVERT(CHAR(12), I.InvoiceDt, 1) AS InvoiceDt, IL.FK_StoveNbr
FROM INVOICE AS I
INNER JOIN INV_LINE_ITEM AS IL ON I.InvoiceNbr = IL.FK_InvoiceNbr
WHERE IL.FK_StoveNbr IS NOT NULL AND InvoiceDt BETWEEN '05/01/02' AND '05/31/02'
ORDER BY I.InvoiceDt;
GO


GO
SELECT * FROM STOVE_REPAIR;
SELECT * FROM STOVE;
PRINT 'CIS275, Lab3, question 10, ten points possible.
Show the type and version with the count of the most repaired stove.
You will use the COUNT() aggregate function with a GROUP BY on type and version.' + CHAR(10);
SELECT T.Type AS MostRepairedTYPE, T.Version AS MostRepairedVERSION
FROM
(SELECT S.Type, S.Version, COUNT(*) AS countnum
FROM STOVE_REPAIR AS SR
INNER JOIN STOVE AS S ON S.SerialNumber = SR.FK_StoveNbr
GROUP BY S.Type, S.Version) AS T
WHERE T.countnum=
(SELECT MAX(countnum) FROM (SELECT S.Type, S.Version, COUNT(*) AS countnum
FROM STOVE_REPAIR AS SR
INNER JOIN STOVE AS S ON S.SerialNumber = SR.FK_StoveNbr
GROUP BY S.Type, S.Version) AS T)
;
GO


GO
PRINT 'Extra and JUST FOR FUN (these queries are NOT required).' + CHAR(10);
GO
PRINT '(1) Project the invoice average total price, minimum total price, and maximum total price.';
GO


GO
PRINT '(2) Now project the same averages in one column.';
GO


GO
-------------------------------------------------------------------------------------
-- This is an anonymous program block. DO NOT CHANGE OR DELETE.
-------------------------------------------------------------------------------------
BEGIN
    PRINT '|---' + REPLICATE('+----',15) + '|';
    PRINT ' End of CIS275 Lab3' + REPLICATE(' ',50) + CONVERT(CHAR(12),GETDATE(),101);
    PRINT '|---' + REPLICATE('+----',15) + '|';
END;

/*
*************************************************************************************
CIS275, SQL Lab4, 
five questions provided by Vicki Jonathan, Instructor
modified by Jeff fried
PCC using Microsoft SQL Server 2008
date-you-begin-lab your-name-goes-here 
10 June 2012 DUE DATE
-------------------------------------------------------------------------------------
You need to know how to interpret story problems, translate their requirements into 
queries, write queries to class standards, and identify whether output is correct.
-------------------------------------------------------------------------------------
SELECT clause contains formatted projection items one to a line separated by commas
and aliased with user-friendly names in single quotes.
CAST(column_name AS CHAR(#)) for character data where # is best-fit field length.
STR(column_name, precision, scale) for numbers where precision is best-fit field 
    length which includes the decimal point and optional scale is the number of 
    decimal places (use 2 for money, omit for whole numbers).
CONVERT(CHAR(12), column_name, #) for dates where # is the style number for date.
SQL keywords and table names are uppercase. Every query to end with a semi-colon.
*************************************************************************************
*/

USE FiredUp    -- ensures correct database is active


GO
PRINT 'CIS2275, Lab4, question 1, twenty (20) points possible
What types of stoves have sold in at least three different states and
somewhere in Canada? Display the stove type.' + CHAR(10);
-- -- select statement for all stoves that are made in canada
-- SELECT DISTINCT Stove.Type FROM STOVE
-- INNER JOIN INV_LINE_ITEM AS INV ON INV.FK_StoveNbr = STOVE.SerialNumber
-- INNER JOIN INVOICE AS I ON I.InvoiceNbr = INV.FK_InvoiceNbr
-- INNER JOIN CUSTOMER AS C ON C.CustomerID = I.FK_CustomerID
-- WHERE C.Country = 'CAN'

SELECT Type FROM (
    SELECT US_Stoves.Type, COUNT(US_Stoves.StateProvince) AS Unique_State_Count 
    FROM (
        SELECT DISTINCT Stove.Type, C.StateProvince FROM STOVE 
        INNER JOIN INV_LINE_ITEM AS INV ON INV.FK_StoveNbr = STOVE.SerialNumber
        INNER JOIN INVOICE AS I ON I.InvoiceNbr = INV.FK_InvoiceNbr
        INNER JOIN CUSTOMER AS C ON C.CustomerID = I.FK_CustomerID
        WHERE C.Country = 'USA') AS US_Stoves
GROUP BY Type) AS US_Stoves_States_Count
WHERE Type IN (
    SELECT DISTINCT Stove.Type FROM STOVE
    INNER JOIN INV_LINE_ITEM AS INV ON INV.FK_StoveNbr = STOVE.SerialNumber
    INNER JOIN INVOICE AS I ON I.InvoiceNbr = INV.FK_InvoiceNbr
    INNER JOIN CUSTOMER AS C ON C.CustomerID = I.FK_CustomerID
    WHERE C.Country = 'CAN'
)
GO


GO
PRINT 'CIS275, Lab4, question 2, twenty (20) points possible
Out of all the invoices containing FiredAlways stoves, show those with the three 
highest total price. Display the invoice number, invoice date, and totalprice. ' + CHAR(10);
-- SELECT TOP 3 InvoiceNbr, InvoiceDt, TotalPrice FROM
SELECT DISTINCT TOP 3 WITH TIES I.InvoiceNbr, CONVERT(CHAR(12), I.InvoiceDt, 1) AS InvoiceDt, STR(I.TotalPrice, 8, 2) AS TotalPrice
FROM INVOICE I 
INNER JOIN INV_LINE_ITEM INV ON INV.FK_InvoiceNbr = I.InvoiceNbr
INNER JOIN STOVE S ON S.SerialNumber = INV.FK_StoveNbr
WHERE S.Type = 'FiredAlways'
ORDER BY TotalPrice DESC, I.InvoiceNbr, InvoiceDt


-- (
--     SELECT I.InvoiceNbr, CONVERT(CHAR(12), I.InvoiceDt, 1) AS InvoiceDt, STR(I.TotalPrice, 8, 2) AS TotalPrice
--     FROM INVOICE I 
--     INNER JOIN INV_LINE_ITEM INV ON INV.FK_InvoiceNbr = I.InvoiceNbr
--     INNER JOIN STOVE S ON S.SerialNumber = INV.FK_StoveNbr
--     WHERE S.Type = 'FiredAlways'
--     ORDER BY I.TotalPrice DESC
-- );
GO

SELECT * FROM EMPLOYEE
GO
PRINT 'CIS275, Lab4, question 3, twenty (20) points possible
Who has sold stoves in the two most popular states?
Display the employee number, employee name, the name of the two most popular states, 
and the number of stoves sold by the employees in those states.  (''Most popular 
state'' means the state or states for customers who purchased the most stoves, 
regardless of the stove type and version. Do not hardcode a specific state into your 
query.)' + CHAR(10);
SELECT E.EmpID, E.Name, StateProvince, COUNT(*) AS Stoves_Sold
FROM EMPLOYEE E
INNER JOIN INVOICE I ON I.FK_EmpID = E.EmpID
INNER JOIN CUSTOMER C ON C.CustomerID = I.FK_CustomerID
INNER JOIN INV_LINE_ITEM INV ON INV.FK_InvoiceNbr = I.InvoiceNbr
WHERE FK_StoveNbr IS NOT NULL AND C.StateProvince IN 
--- query to select the top 3 states with the most stove sales
--- need to use two inner joins to relate the one to many relationship from invoices to items
(SELECT TOP 2 WITH TIES StateProvince
FROM CUSTOMER C
INNER JOIN INVOICE I ON C.CustomerID = I.FK_CustomerID
INNER JOIN INV_LINE_ITEM INV ON INV.FK_InvoiceNbr = I.InvoiceNbr
WHERE FK_StoveNbr IS NOT NULL
GROUP BY StateProvince
ORDER BY COUNT(*) DESC)
GROUP BY E.Name, E.EmpID, StateProvince
ORDER BY StateProvince, COUNT(*) DESC



GO


GO
PRINT 'CIS275, Lab4, question 4, twenty (20) points possible
Show employees having sold the type and version of stove that has been repaired the 
most? Display the employee name, stove type, stove version, and number of times 
repaired. If there is more than one employee then display them all. Do not hardcode 
a specific type or version into your query. (We are not asking for the person whose 
stoves get repaired the most. The employee who sold the most of the least reliable 
stove may have gotten lucky with their particular sales.)' + CHAR(10);
SELECT E.Name, S.Type, S.Version, Count(*) AS Stoves_Repaired
FROM EMPLOYEE E
INNER JOIN INVOICE I ON I.FK_EmpID = E.EmpID
INNER JOIN CUSTOMER C ON C.CustomerID = I.FK_CustomerID
INNER JOIN INV_LINE_ITEM INV ON INV.FK_InvoiceNbr = I.InvoiceNbr
INNER JOIN STOVE S ON INV.FK_StoveNbr = S.SerialNumber
INNER JOIN STOVE_REPAIR SR ON S.SerialNumber = SR.FK_StoveNbr
WHERE S.Type = (SELECT T.Type from (SELECT TOP 1 WITH TIES Type, Version, COUNT(*) AS Count FROM Stove 
JOIN Stove_Repair ON Stove.SerialNumber = Stove_Repair.FK_StoveNbr
GROUP BY Type, Version
ORDER BY Count DESC) AS T)
AND
S.Version = (SELECT T.Version from (SELECT TOP 1 WITH TIES Type, Version, COUNT(*) AS Count FROM Stove 
JOIN Stove_Repair ON Stove.SerialNumber = Stove_Repair.FK_StoveNbr
GROUP BY Type, Version
ORDER BY Count DESC) AS T)
GROUP BY E.Name, S.Type, S.Version
ORDER BY Count(*);


-- SELECT * FROM STOVE_REPAIR;


-- (SELECT TOP 1 WITH TIES Type, Version, COUNT(*) AS Count FROM Stove 
-- JOIN Stove_Repair ON Stove.SerialNumber = Stove_Repair.FK_StoveNbr
-- GROUP BY Type, Version
-- ORDER BY Count DESC)
GO



-- SELECT * FROM STOVE;
GO
PRINT 'CIS275, Lab4, question 5, twenty (20) points possible
Which invoice has the second-lowest total price among invoices that do not include a 
sale of a FiredAlways stove? Display the invoice number, invoice date, and invoice 
total price. If there is more than one invoice then display all of them. (Finding 
invoices that do not include a FiredAlways stove is NOT the same as finding invoices 
where a line item contains something other than a FiredAlways stove -- invoices have 
more than one line. Avoid a JOIN with STOVE since the lowest price may not involve 
any stove sales.)' + CHAR(10);
SELECT TOP 1 WITH TIES InvoiceNbr, InvoiceDt, TotalPrice FROM 
(
SELECT TOP 2 WITH TIES INVOICE.InvoiceNbr, CONVERT(CHAR(12), INVOICE.InvoiceDt, 1) AS InvoiceDt, STR(INVOICE.TotalPrice, 8, 2) AS TotalPrice
FROM INVOICE
WHERE InvoiceNbr IN 
(SELECT FK_InvoiceNbr FROM INV_LINE_ITEM WHERE FK_StoveNbr NOT IN (SELECT SerialNumber FROM STOVE WHERE Type = 'FiredAlways'))
ORDER BY TotalPrice
) AS T
ORDER BY TotalPrice DESC
;
GO






GO
-------------------------------------------------------------------------------------
-- This is an anonymous program block. DO NOT CHANGE OR DELETE.
-------------------------------------------------------------------------------------
BEGIN
    PRINT '|---' + REPLICATE('+----',15) + '|';
    PRINT ' End of CIS275 Lab4' + REPLICATE(' ',50) + CONVERT(CHAR(12),GETDATE(),101);
    PRINT '|---' + REPLICATE('+----',15) + '|';
END;



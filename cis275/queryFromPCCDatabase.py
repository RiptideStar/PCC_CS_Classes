import pyodbc 
# Some other example server values are
# server = 'localhost\sqlexpress' # for a named instance
# server = 'myserver,port' # to specify an alternate port
server = 'tcp:cisdbss.pcc.edu' 
database = 'FiredUp' 
username = '275student' 
password = '275student' 
cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+server+';DATABASE='+database+';UID='+username+';PWD='+ password)
cursor = cnxn.cursor()

   
cursor.execute("SELECT TOP 10 * FROM Customer;") 
row = cursor.fetchone() 
print("Jeff's example sql query: ")
while row: 
    print(row[0], row[1])
    row = cursor.fetchone()

print()
print("Kyle Zhang's sql query: ")
cursor.execute("SELECT TOP 10 * FROM INV_LINE_ITEM WHERE FK_StoveNbr IS NOT NULL;") 
row = cursor.fetchone() 
while row: 
    print(row[0], row[1], row[2])
    row = cursor.fetchone()    
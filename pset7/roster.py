# TODO
# TODO
import csv
from sys import argv
from cs50 import SQL
db = SQL("sqlite:///students.db")

sql = "SELECT first,middle,last,birth FROM students WHERE house = %s ORDER BY last"
house = argv[1]

table = db.execute(sql,house)
if len(argv) != 2:
    print("Error")

for dictionary in table:
    if dictionary['middle'] == None:
        string="{first} {last}, born {birth}".format(
            first=dictionary['first'], last=dictionary['last'],birth=dictionary['birth'])
    else:
        string="{first} {middle} {last}, {birth}".format(
            first=dictionary['first'], middle=dictionary['middle'], last=dictionary['last'], birth=dictionary['birth'])
    print(string)

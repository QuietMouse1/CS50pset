# TODO
import csv
from sys import argv
from cs50 import SQL

db = SQL("sqlite:///students.db")

if len(argv) != 2:
    print("Error")
# Insert show by substituting values into each ? placeholder

with open(argv[1], "r") as file:
    csv_reader = csv.DictReader(file, delimiter=',')
    for row in csv_reader:
        # Put the names in
        name = row['name'].split()
        if len(name) == 3:
            first = name[0]
            middle = name[1]
            last = name[2]
        else:
            first = name[0]
            middle = None
            last = name[1]
        house = row['house']
        birth = row['birth']
        db.execute("INSERT INTO students (first, middle, last, house,birth) VALUES(?, ?, ?, ?,?)",
            first, middle, last, house, birth)

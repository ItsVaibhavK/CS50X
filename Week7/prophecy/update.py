from cs50 import SQL

db = SQL("sqlite:///roster.db")

# execute returns a list of dictionaries
rows = db.execute("SELECT * FROM students")

# update only_students table
for row in rows:
    db.execute("INSERT INTO only_students (id, student_name) VALUES (?, ?)", row["id"], row["student_name"])

# update houses table
houselist = []
headlist = []
for row in rows:
    if not row["house"] in houselist:
        houselist.append(row["house"])
    if not row["head"] in headlist:
        headlist.append(row["head"])

for i in range(len(houselist)):
    db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", houselist[i], headlist[i])

# update assignments table
for row in rows:
    db.execute("INSERT INTO assignments (student_id, house_id) VALUES ((SELECT id FROM students WHERE student_name = ?), (SELECT id FROM houses WHERE house = ?))", row["student_name"], row["house"])

f = open("input")

correct_order = {}

for line in f:
    if "|" in line:
        pages = line.split("|")
        if pages[0] not in correct_order:
            pass
            #creez dictionarul cu cheile, iar fiecare cheie va avea un tuplu cu 2 seturi
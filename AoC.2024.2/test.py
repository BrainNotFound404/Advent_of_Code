l = [1, 2, 3]
for i in range(len(l)):
    if i == len(l) - 1:
        print(i)
        l.pop(i)

print(l)

    
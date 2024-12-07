f = open("input")

correct_order = {}

sum = 0

for line in f:
    if line[len(line) - 1] == "\n":
        line = line[:len(line) - 1]

    if "|" in line:
        pages = line.split("|")
        if pages[0] not in correct_order:
            correct_order[pages[0]] = set()
        
        if pages[1] not in correct_order:
            correct_order[pages[1]] = set()

        correct_order[pages[0]].add(pages[1])
    elif "," in line:
        numbers = line.split(",")
        #print(numbers)
        for i in range(len(numbers) - 1):
            is_correct = True

            for j in range(i + 1, len(numbers)):
                if numbers[i] in correct_order[numbers[j]]:
                    is_correct = False
                    break

            if not is_correct:
                break
        if not is_correct:
            #print(numbers[len(numbers) // 2])
            for i in range(len(numbers) - 1):
                for j in range(i + 1, len(numbers)):
                    if numbers[i] in correct_order[numbers[j]]:
                        numbers[i], numbers[j] = numbers[j], numbers[i]
            
            sum += int(numbers[len(numbers) // 2])


#print(correct_order)

f.close()
print(sum)

            #creez dictionarul cu cheile, iar fiecare cheie va avea un tuplu cu 2 seturi
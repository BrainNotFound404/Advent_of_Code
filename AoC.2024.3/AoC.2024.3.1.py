import re

f = open("input")

sum = 0

for line in f:
    pattern = r"mul\((\d{1,3}),(\d{1,3})\)"
    matches = re.findall(pattern, line)

    for match in matches:
        sum += int(match[0]) * int(match[1])

f.close()
print(sum)
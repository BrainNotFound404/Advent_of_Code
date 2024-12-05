
import re

f = open("input")

sum = 0
dont = r"don't\(\)"
do = r"do\(\)"
pattern = r"mul\((\d{1,3}),(\d{1,3})\)"

line = f.read()

start_index = 0
end_index = re.search(dont, line).end()

while True:

    matches = re.findall(pattern, line[start_index:end_index])

    for match in matches:
        sum += int(match[0]) * int(match[1])

    start_index = end_index

    try:
        start_index += re.search(do, line[start_index:]).end()
    except AttributeError:
        break

    end_index = start_index

    try:
        end_index += re.search(dont, line[end_index:]).end()
    except AttributeError:
        end_index = len(line)

print(sum)
f.close()

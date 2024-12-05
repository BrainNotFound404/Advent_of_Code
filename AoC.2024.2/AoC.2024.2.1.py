f = open("input")

safe_reports = 0
for line in f:
    report = [int(x) for x in line.split()]
    if report[0] < report[1]:
        for i in range(len(report) - 1):
            if report[i] >= report[i + 1] or report[i + 1] - report[i] > 3:
                break
        else:
            safe_reports += 1
    if report[0] > report[1]:
        for i in range(len(report) - 1):
            if report[i] <= report[i + 1] or report[i] - report[i + 1] > 3:
                break
        else:
            safe_reports += 1
f.close()
print(safe_reports)
f = open("input")

safe_reports = 0
for line in f:
    report = [int(x) for x in line.split()]
    i = 0
    first_equal = False
    if report[0] == report[1]:
        report.pop(0)
        first_equal = True
    if report[0] > report[1]:
        report = report[::-1]
    if report[0] <= report[1]:
        if not first_equal:
            for i in range(len(report) - 1):
                if report[i] >= report[i + 1] or report[i + 1] - report[i] > 3:
                    report.pop(i + 1)
                    break
        
        for j in range(i, len(report) - 1):
            if report[j] >= report[j + 1] or report[j + 1] - report[j] > 3:
                break
        else:
            safe_reports += 1
    

print(safe_reports)
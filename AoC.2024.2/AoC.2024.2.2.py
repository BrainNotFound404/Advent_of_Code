def is_safe(report):
    def valid_report(report):
        inc = all(1 <= report[i + 1] - report[i] <= 3 for i in range(len(report) - 1))
        dec = all(1 <= report[i] - report[i + 1] <= 3 for i in range(len(report) - 1))
        return inc or dec

    if valid_report(report):
        return True

    for i in range(len(report)):
        modified_report = report[:i] + report[i + 1:]
        if valid_report(modified_report):
            return True

    return False

safe_reports = 0
f = open("input")
for line in f:
    report = [int(x) for x in line.split()]
    if is_safe(report):
        safe_reports += 1
f.close()
print(safe_reports)

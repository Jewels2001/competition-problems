

def checkDecreasing(line):
    last = -1
    for i in range(0, len(line)):
        if i == 0:
            last = int(line[i])
            continue
        if line[i] >= last:
            return False
        last = int(line[i])
    return True

def checkIncreasing(line):
    last = -1
    for i in range(0, len(line)):
        if i == 0:
            last = line[i]
            continue
        if line[i] <= last:
            return False
        last = int(line[i])
    return True

def check_one_three(line):
    last = -1
    for i in range(0, len(line)):
        if i == 0:
            last = line[i]
            continue
        if abs(line[i] - last) < 1 or abs(line[i] - last) > 3:
            return False
        last = int(line[i])
    return True


arr = []



file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        arr.append([ int(x) for x in line.split(" ")])
        
ans = 0
for string in arr:
    if checkIncreasing(string) or checkDecreasing(string):
        if check_one_three(string):
            ans += 1
        
print(ans)
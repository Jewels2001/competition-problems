

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


def gen_pos(line):
    all_str = []
    for i in range(0, len(line)):
        copied_list = line.copy()
        copied_list.pop(i)
        all_str.append(copied_list)
        
    return all_str

def check_one(line):
    if checkIncreasing(a) or checkDecreasing(a):
        if check_one_three(a):
            return True
    return False
    


arr = []



file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        arr.append([ int(x) for x in line.split(" ")])
        
ans = 0
for string in arr:
    all_str = gen_pos(string)
    
    all_str.append(string)

    for a in all_str:
        if check_one(a):
            ans += 1
            break
        
        
print(ans)
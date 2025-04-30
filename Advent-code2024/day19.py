




towels = []
line1 = ""
patterns = []


def f(pattern):
    if not pattern:
        return True
    
    # for each towel, check if pattern startswith(towel)
    for towel in towels:
        if pattern.startswith(towel):
            if f(pattern[len(towel):]):
                return True
    
    return False



file_name = input("Path to file name:\n")
with open(file_name) as file:
    towels = file.readline().rstrip('\n').split(", ")
    file.readline()
    while line := file.readline().rstrip('\n'):
        patterns.append(line)
    

ans = 0
for pattern in patterns:
    if f(pattern):
        ans += 1
        
print(ans)
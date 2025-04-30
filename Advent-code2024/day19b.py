




towels = []
line1 = ""
patterns = []

# ans_dp = str : int
ans_dp = {}


def f(pattern):
    if not pattern:
        return 1
    if pattern in ans_dp:
        return ans_dp[pattern]
    
    total = 0  
      
    # for each towel, check if pattern startswith(towel)
    for towel in towels:
        if pattern.startswith(towel):
            total += f(pattern[len(towel):])

    ans_dp[pattern] = total
    return total



file_name = input("Path to file name:\n")
with open(file_name) as file:
    towels = file.readline().rstrip('\n').split(", ")
    file.readline()
    while line := file.readline().rstrip('\n'):
        patterns.append(line)
    

ans = 0
for pattern in patterns:
    ans_dp = {}
    ans += f(pattern)
        
print(ans)
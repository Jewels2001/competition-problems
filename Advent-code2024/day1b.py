
arr1 = []
arr2 = []

sim_scores = {}


file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        arr1.append(int(line.split(" ", 1)[0]))
        # for a in range(1, len(line))
        line = line.split(" ")[1:]
        for a in line:
            if a is not '':
                arr2.append(int(a))


print(sim_scores)

for a in arr1:
    if a not in sim_scores:
        sim_scores[a] = 0

print(sim_scores.keys())
    
for b in arr2:
    if b in sim_scores:
        sim_scores[b] += 1
 
print(sim_scores)
 
ans = 0
for a in arr1:
    ans += a * sim_scores[a]
 
       
#arr1.sort()
#arr2.sort()


assert(len(arr1) == len(arr2))

# ans = 0

# for i,j in zip(arr1, arr2):
#     ans += abs(i - j)
    
print(ans)
        
    
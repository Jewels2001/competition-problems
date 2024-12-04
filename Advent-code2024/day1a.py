

arr1 = []
arr2 = []



file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        arr1.append(int(line.split(" ", 1)[0]))
        # for a in range(1, len(line))
        line = line.split(" ")[1:]
        for a in line:
            if a is not '':
                arr2.append(int(a))
        
arr1.sort()
arr2.sort()

print(arr1)
print(arr2)

print(len(arr1))
print(len(arr2))

assert(len(arr1) == len(arr2))


ans = 0

for i,j in zip(arr1, arr2):
    ans += abs(i - j)
    
print(ans)
        
    
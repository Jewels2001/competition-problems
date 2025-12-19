
from sys import stdin

def find_largest(l):
    first_largest_index = 0
    second_largest_index = 1
    

    for i in range(1, len(l)):
        num = int(l[i])
        if i < len(l) - 1:
            if num > int(l[first_largest_index]):
                first_largest_index = i
                second_largest_index = i+1
    for i in range(first_largest_index+1, len(l)):
        num = int(l[i])
        if num > int(l[second_largest_index]):
            second_largest_index = i

     
    ans = f"{l[first_largest_index]}{l[second_largest_index]}"
    #print(ans)
    return ans 


ans = 0

for line in stdin:
    line = line.strip()
    # have one line (process)
    ans += int(find_largest(line))

print("ANS: ", ans)



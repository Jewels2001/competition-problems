
from sys import stdin


def next_index(last, cur_index, left, l):
    this_index = cur_index
    for i in range(last+1, len(l)):
        num = int(l[i])
        if i < len(l) - left:
            if num > int(l[this_index]):
                this_index = i
    return this_index


def find_largest(l):
    first_largest_index = 0
    second_largest_index =  1
    
    ans = f""

    ## EDITS AFTER:    
    #for i in range(11, -1, -1):
    #    temp = next_index(first_largest_index, second_largest_index, i, l)
    #    ans += f"{l[temp]}"
    #    #update
    #    first_largest_index = temp
    #    second_largest_index = temp + 1
    ## END EDITS AFTER
    

    #for i in range(1, len(l)):
    #    num = int(l[i])
    #    if i < len(l) - 11:
    #        if num > int(l[first_largest_index]):
    #            first_largest_index = i
    #            second_largest_index = i+1
    #ans += f"{l[first_largest_index]}"

    
    #for i in range(10, -1, -1):
    #    #last_temp = first_largest_index
    #    #curr_temp = second_largest_index
    #    temp = next_index(first_largest_index,second_largest_index,i,l)
    #    ans += f"{l[temp]}"
    #    #update
    #    first_largest_index = temp
    #    second_largest_index = temp + 1

    #for i in range(first_largest_index+1, len(l)):
    #    num = int(l[i])
    #    if num > int(l[second_largest_index]):
    #        second_largest_index = i

    #print(ans)
    return ans 


ans = 0

for line in stdin:
    line = line.strip()
    # have one line (process)
    ans += int(find_largest(line))

print("ANS: ", ans)



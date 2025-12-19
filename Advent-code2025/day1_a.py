
from sys import stdin



arr = [i for i in range(0, 100)]


def get_one_input(line):
    #rotation = str(input())
    rotation = str(line)
    s = rotation[0]
    #print(rotation[1:].strip())
    #print(type(rotation[1:]))
    num = int(rotation[1:].strip())
    return (s, num)



def move_pointer(s, num, curr_pointer):
    new_pointer = curr_pointer
    if s == "R":
        new_pointer = new_pointer + num
    else:
        new_pointer = new_pointer - num

    if new_pointer > 99:
        #new_pointer = new_pointer - 1
        new_pointer = new_pointer % 100
    if new_pointer < 0:
        new_pointer = new_pointer % 100
        #new_pointer = new_pointer + 1
        #new_pointer = new_pointer % 99
    if (new_pointer > 99 or new_pointer < 0):
        print("OH NO")
    return new_pointer

def check_if_zero(curr):
    if curr == 0:
        return 1
    return 0

curr = 50
ans = 0


for line in stdin:
    #line = file.readline()
    # process one line
    s, num = get_one_input(line)
    curr = move_pointer(s, num, curr)
    print("CURR: ", curr)
    if curr == 0:
        ans += 1
    #ans += check_if_zero(move_pointer(s, num, 50))
    # end of file
    if not line:
        break

"""
with open('aoc_day1.txt', 'r') as file:
    line = file.readline()
    # process one line
    s, num = get_one_input(line)
    curr = move_pointer(s, num, 50)
    print("CURR: ", curr)
    ans += check_if_zero(move_pointer(s, num, 50))
    # end of file
    if not line:
        break
"""

print("ANS: ", ans)

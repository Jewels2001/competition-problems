
import re

lines = ""

file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        lines += line


matches = re.findall(r"mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\)", lines)


ans = 0
do = True
for match in matches:
    if re.match(r"do\(\)", match):
        do = True
    elif re.match(r"don't\(\)", match):
        do = False
    elif do:
        temp = match.strip("mul()")
        a = int(temp.split(",")[0])
        b = int(temp.split(",")[1])
        ans += (a*b)

print(ans)



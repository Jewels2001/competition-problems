
import re


lines = ""


file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        lines += line


matches = re.findall(r"mul\([0-9]{1,3},[0-9]{1,3}\)", lines)


ans = 0
for match in matches:
    temp = match.strip("mul()")
    a = int(temp.split(",")[0])
    b = int(temp.split(",")[1])
    ans += (a*b)

print(ans)



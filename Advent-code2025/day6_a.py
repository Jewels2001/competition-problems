
from sys import stdin


add_ans = {}
mult_ans = {}

ans = 0

for line in stdin:
    parts = line.split()
      
    for i in range(0, len(parts)):
        part = parts[i]
        if not part.isdigit():
            print("signs")
            if part == "*":
                ans += mult_ans[i]
            elif part == "+":
                ans += add_ans[i]
            continue
        part = int(part)
        if i in add_ans:
            add_ans[i] += part
        else:
            add_ans[i] = part 

        if i in mult_ans:
            mult_ans[i] *= part
        else:
            mult_ans[i] = part

print("ANS: ", ans)

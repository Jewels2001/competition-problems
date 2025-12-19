
from sys import stdin

fresh_s = []
fresh_e = []
all_i = []



def check_in_range(val):
    for s, e in zip(fresh_s, fresh_e):
        #print("S: ", s)
        #print("E: ", e)
        #print("VAL: ", val)
        if val >= s and val <= e:
            #print("in between")
            return True
    return False



done_fresh = False

for line in stdin:
    line = line.strip()
    if not line:
        print("empty")
        done_fresh = True
        continue
    
    if not done_fresh:
        print(line)
        start, end = line.split("-")
        fresh_s.append(int(start))
        fresh_e.append(int(end))
        continue
        
    all_i.append(int(line))

ans = 0
for ing in all_i:
    print(ing)
    if check_in_range(ing):
        print("FRESHVACADOS")
        ans += 1
print("ANS: ", ans)

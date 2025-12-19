

# ids:
# - can only be even length
# split in half both are the same



def check_if_invalid(s):
    l = len(s)
    #print("S: ", s)
    #print("LEN: ", l)
    ans = 0
    for i in range(1, l+1):
        #print("I:", i)
        #print( l % i)
        if l % i != 0:
            continue
        divi = int(l / i)
        part = s[:divi]
        #print("DIVI: ", divi)
        #print("PART: ", part)
        add_true = False
        for j in range(1,i): #range(1,divi+1):
            #print("NEXT PART: ", s[divi*j:divi*j+divi])
            #breakpoint()
            if s[divi*j:divi*j+divi] != part:
                add_true = False
                break
            add_true = True
        if add_true:
            #print("ADDED PART: ", s)
            return int(s)

            #breakpoint()

    
    #if l % 2 != 0:
    #    return 0 #False
    #half = int(l / 2)
    #print("FIRST HALF: ", s[:half])
    #print("SECOND: ", s[half:])
    
    #if s[:half] == s[half:]:
    #    return int(s) #True
    #return 0 #False
    return ans

"""
s = input()
print(check_if_invalid(s))
exit()
"""

line = ""
with open('aoc_day2_official.txt', 'r') as file:
    line = file.readline()
    # process one line
full = line

ans = 0

for r in full.split(','):
    #print(r)
    start_s, end_s = r.split('-')
    start = int(start_s)
    end = int(end_s)
    for i in range(start, end+1):
        ans += check_if_invalid(str(i))
    #print("\n\n")

print("ANS: ", ans)

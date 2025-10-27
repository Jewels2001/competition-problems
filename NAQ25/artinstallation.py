
r,g,b = [int(x) for x in input().split()]
cr, cg, cb = [int(x) for x in input().split()]
crg, cgb = [int(x) for x in input().split()]


# red 
# green
# blue

# subtract owned from need totals
r = r - cr
g = g - cg
b = b - cb

#  if need is 0 or negative, done

bought = 0

# try to buy remaining red
if r > 0:
    temp = r - crg
    if temp > 0:
        print(-1)
        exit()
    elif temp == 0:
        bought = bought + r
        r = 0
        crg = 0
    else:
        bought = bought + r
        crg = crg - r
        r = 0

# try to buy remaining blue
if b > 0:
    temp = b - cgb
    if temp > 0:
        print(-1)
        exit()
    elif temp == 0:
        bought = bought + b
        cgb = 0
        b = 0
    else:
        bought = bought + b
        cgb = cgb - b
        b = 0
# rest for green
if g > 0:
    temp1 = g - cgb
    if temp1 > 0:
        g = g - cgb
        bought = bought + cgb
        temp2 = g - crg
        if temp2 > 0:
            print(-1)
            exit()
        elif temp2 == 0:
            bought = bought + g
            g = 0
        else:
            bought = bought + g
            g = 0
    elif temp1 == 0:
        bought = bought + g
        g = 0
    else:
        bought = bought + g
        g = 0
   

# if still positive left, -1
if r > 0 or g > 0 or b > 0:
    print(-1)
else:
    print(bought)






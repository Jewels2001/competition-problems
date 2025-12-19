
from sys import stdin


def calc_area(p1,p2):
    y1, x1 = p1
    y2, x2 = p2
    l = (max(x2, x1) + 1) - min(x2, x1)
    w = abs(max(y2, y1) - min(y2, y1)) + 1
    print("L:", l, "W:", w)
    return l * w
    #return (abs(x2 - x1) - 1) * (abs(y2 - y1) + 1)


#grid = []

points = []

#i = 0
for line in stdin:
    #line = line.strip()
    line = line.strip().split(",")
    i = int(line[0])
    j = int(line[1])
    points.append((i,j))
    #grid.append(line)
    #j = 0 
    #for a in line:
    #    if a == "#":
    #        points.append((i,j))
    #    j += 1
    
    #i += 1

area = 0

for p1 in points:
    for p2 in points:
        if p1 == p2:
            continue
        temp_area = calc_area(p1, p2)
        print(p1, p2, temp_area, area)
        area = max(temp_area, area)

print("ANS:", area)



#for l in grid:
#    for point in l:






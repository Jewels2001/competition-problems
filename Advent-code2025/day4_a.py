
from sys import stdin


def check_out_bounds(grid, i, j):
    c = len(grid)
    r = len(grid[0])
    if i < 0 or i >= c or j < 0 or j >= r:
        return True
    return False


def check_around(grid, i, j):
    count = 0
    d1 = [-1, 1, 0, 0, -1, -1, 1, 1]
    d2 = [0, 0, -1, 1, -1, 1, 1, -1]
    for x, y in zip(d1, d2):
        #print(i+x, j+y)
        if check_out_bounds(grid, i+x, j+y):
            continue
        spot = grid[i+x][j+y]
        if spot == "@":
            count += 1
    if count < 4:
        return True
    return False




# read grid
grid = []

for line in stdin:
    line = line.strip()
    temp = []
    for l in line:
        temp.append(l)
    grid.append(temp)

ans = 0

#for i in grid:
#    for j in i:
for i in range(0, len(grid)):
    for j in range(0, len(grid[0])):
        if grid[i][j] == "@":
            ans += check_around(grid, i, j)
        
print("ANS: ", ans)

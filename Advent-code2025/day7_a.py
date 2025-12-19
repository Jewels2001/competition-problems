
from sys import stdin


grid = []


def out_of_bounds(i, j):
    i_len = len(grid)
    j_len = len(grid[0])
    if i < 0 or i >= i_len or j < 0 or j >= j_len:
        return True
    return False


cur_beams = []
row_beams = []


def set_start(i, j, cur_beams):
    for r in range(0, len(grid[0])):
        if r == j:
            cur_beams.append("|")
        else:
            cur_beams.append(".")


def process_splitter(i, j, row_beams, cur_beams):
    # first check if splitter was hit
    # if not, return false
    #print(cur_beams)
    #print("I: ", i, "J: ", j)
    if cur_beams[j] != "|":
        return 0
    # remove this spot from beams
    row_beams[j] = "."
    # add more beams
    l_spot = (i, j-1)
    r_spot = (i, j+1)
    # check if spot is in bounds
    if not out_of_bounds(l_spot[0], l_spot[1]):
        row_beams[l_spot[1]] = "|"
    if not out_of_bounds(r_spot[0], r_spot[1]):
        row_beams[r_spot[1]] = "|"

    return 1






for line in stdin:
    line = line.strip()
    grid.append(line)

ans = 0

i = 0
for l in grid:
    j = 0
    row_beams = cur_beams
    for c in l:
        if c == "S":
            set_start(i, j, cur_beams)
            #print(cur_beams)
        if c == "^":
            ans += process_splitter(i, j, row_beams, cur_beams)
        j += 1
    print(cur_beams)
    cur_beams = row_beams
    i += 1

print("ANS: ", ans)


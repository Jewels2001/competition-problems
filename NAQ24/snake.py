


def get_index(i, j, r, c):
    







r, c = [int(x) for x in input().split()]

grid = []

APPLE = (-1, -1)

for row in range(0, r):
    line = input()
    col = []
    for x, cell in enumerate(line):
        col.append(cell)
        if cell == 'A':
            APPLE = (row, x)
    grid.append(col)


print(grid)
print(APPLE)



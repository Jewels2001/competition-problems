


def get_index(i, j, r, c):
    x = 1
    y = 1
    
    return [x, y]

move_r = [-1, 1, 0, 0]
move_c = [0, 0, -1, 1]









r, c = [int(x) for x in input().split()]

grid = []

APPLE = (-1, -1)
snake = []

for row in range(0, r):
    line = input()
    col = []
    for x, cell in enumerate(line):
        col.append(cell)
        if cell == 'A':
            APPLE = (row, x)
        if cell in "0123456789abcdef":
            snake.append((cell, row, x))
    grid.append(col)


snake.sort()

print(grid)
print(APPLE)
print(snake)

stack = []

# dfs
visited = None
start = snake[0]

stack.append(start)
while(stack):
    
    



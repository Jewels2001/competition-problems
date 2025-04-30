
grid = []
obstacles = []
start = {0:0,1:0}

def check_bounds(x, y, n, m):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    return True

        
def turn_guard(guard):
    if guard == "^":     
        guard= ">"
    elif guard == ">":
        guard = "V"
    elif guard == "V":
        guard = "<"
    elif guard == "<":
        guard = "^"
    return guard


def update_next_step(i, j, guard):
    next_step = {0:0,1:0}
    next_step[0] = i
    next_step[1] = j
    # check next step
    if guard == "^":     
        next_step[0] -= 1
    elif guard == ">":
        next_step[1] += 1
    elif guard == "V":
        next_step[0] += 1
    elif guard == "<":
        next_step[1] -= 1
    return next_step
    

def walk(i, j, n, m, grid, guard):
    # init
    next_step = update_next_step(i, j, guard)
    grid[i] = grid[i][0:j] +"*" + grid[i][j+1:]

    
    while check_bounds(next_step[0], next_step[1], n, m):
        # while still in bounds...
        
        # > check if guard is at "#"
        while grid[next_step[0]][next_step[1]] == "#":
            guard = turn_guard(guard)
            next_step = update_next_step(i, j, guard)
        # move guard
        # move for real
        if guard == "^":     
            i -= 1
        elif guard == ">":
            j += 1
        elif guard == "V":
            i += 1
        elif guard == "<":
            j -= 1
            
        next_step = update_next_step(i, j, guard)
        # set current space to *
        grid[i] = grid[i][0:j] +"*" + grid[i][j+1:]
        

    return grid
    
        

file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        grid.append(line)
        
for i in range(0, len(grid)):
    for j in range(0, len(grid[0])):
        if grid[i][j] == '^':
            start[0] = i
            start[1] = j
            
                    
print(start[0])
print(start[1])

new_grid = grid.copy()
    
new_grid = walk(start[0], start[1], len(grid), len(grid[0]), new_grid, "^")


ans = 0
for i in range(0, len(grid)):
    # print(grid[i])
    for j in range(0, len(grid[0])):
    
        if grid[i][j] == "*":
            ans += 1
            
            
print("ANS:", ans)

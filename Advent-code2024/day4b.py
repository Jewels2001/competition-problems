
grid = []

r = [-1, -1,1,1]
c = [-1, 1,-1,1]


def check_bounds(x, y, n, m):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    return True

def check_one_spot(grid, i, j, letter_in_word=1):
    WORD = "MAS"
    found = False
    # assume start on an 'A' I guess
    # only need to check diagonals
    
    # movement for i, j
    spot_1a = [-1, -1]
    spot_1b = [1, 1]
    spot_2a = [-1, 1]
    spot_2b = [1, -1]
    

    new_strA = ""
    new_strA += grid[i+spot_1a[0]][j+spot_1a[1]]
    new_strA += grid[i+spot_1b[0]][j+spot_1b[1]]
    
    new_strB = ""
    new_strB += grid[i+spot_2a[0]][j+spot_2a[1]]
    new_strB += grid[i+spot_2b[0]][j+spot_2b[1]]
    
    if ("M" in new_strA) and ("S" in new_strA) and ("M" in new_strB) and ("S" in new_strB):
        found = True

    ####
    #XX#
    #XX#
    ###A
    

    return found            
            
    
    

def xmas_exists(grid):
    ans = 0
    n = len(grid)
    m = len(grid[0])
    for i in range(1, n-1):
        for j in range(1, m-1): # for each string in grid
            if "A" == grid[i][j]: # If we find an X (start of XMAS)
                # print(f'Found A at {i},{j}')
                #if find_xmas(grid, i, j, 0): # find the other letters
                #    ans += 1
                ans += check_one_spot(grid, i, j)
    return ans


file_name = input("Path to file name:\n")
with open(file_name) as file:
    while line := file.readline().rstrip('\n'):
        grid.append(line)
        
# will only find XMAS starting from X and continuing to the other 3 letters
ans = xmas_exists(grid)

print(ans)

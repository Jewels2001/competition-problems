import re


grid = []
visited = []

r = [-1, 1, 0, 0, -1, -1,1,1]
c = [0, 0, 1, -1, -1, 1,-1,1]


def check_bounds(x, y, n, m):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    return True

def check_one_spot(grid, i, j, letter_in_word=1):
    WORD = "XMAS"
    count = 0
    for a,b in zip(r,c):
        i2 = i + a
        j2 = j + b
        # do something with indicies
        # these will be all surrounding 8 spots around x
        # if not check_bounds(i2,j2, len(grid), len(grid[0])):
        #     continue
        found_word = False
        for k in range(letter_in_word, len(WORD)):
            if not check_bounds(i2,j2, len(grid), len(grid[0])):
                break
            #do something
            if grid[i2][j2] != WORD[k]:
                break
            i2 += a
            j2 += b
            if WORD[k] == "S":
                found_word = True
        if found_word:
            count += 1 
            found_word = False
    return count            
            
    
    
# def find_xmas(grid, i, j, letter_in_word=0):
#     if letter_in_word == 4:
#         return True
#     if not check_bounds(i, j, len(grid), len(grid[0])):
#         return False
#     adj_visited = []

#     # check all 8 around for M
    
#     found = (find_xmas(grid, i+1, j, letter_in_word+1) or 
#              find_xmas(grid, i - 1, j, letter_in_word+1) or 
#              find_xmas(grid, i, j + 1, letter_in_word+1) or 
#              find_xmas(grid, i, j - 1, letter_in_word+1))
    
#     word = "XMAS"
    
#     #print(f"found letter {word[letter_in_word] if grid[i][j] == word[letter_in_word] else '?'}")
    
#     a = grid[i][j] == word[letter_in_word]
#     return found

    # checks to see if adjacent letters spell xmas


def xmas_exists(grid):
    ans = 0
    n = len(grid)
    m = len(grid[0])
    for i in range(0, n):
        for j in range(0, m): # for each string in grid
            if "X" == grid[i][j]: # If we find an X (start of XMAS)
                print(f'Found X at {i},{j}')
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

import sys

x = 4
y = 4

times = 6
print(f'{x} {y} .')
sys.stdout.flush()

x = 2
y = 2

grid = [][]


def parse(x, ans, moved):
    if ans == "Same":
        print("It was same")
        x = x + 2
    elif ans == "Closer":
        print("It was closer")
        x = x + 1
    elif ans == "Farther":
        x = x + 5
    return x


for i in range(0, times):
    print(f'{x} {y} ?')
    sys.stdout.flush()
    ans = input()
    x = parse(x, ans, False)
    

    
print(f'{x} {y} !')
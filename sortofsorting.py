n = int(input())
while n != 0:
    # input
    names = [input().strip() for a in range(0, n)]

    names.sort(key=lambda x: (x[0], x[1]))

    for i in names:
        print(i)
    print()
    n = int(input())



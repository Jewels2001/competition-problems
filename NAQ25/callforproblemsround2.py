
n, k = [int(x) for x in input().split()]

diffs = {}

for i in range(0, n):
    d = int(input())
    if d in diffs:
        diffs[d] = diffs[d] + 1
    else:
        diffs[d] = 1

total = len(diffs)

if total > k:
    print(k)
else:
    print(total)




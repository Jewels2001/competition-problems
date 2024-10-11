n = int(input())

results = 10 * n

ERR = 2 * n

nums = {}
ans = []

for i in range(0, results):
    draw = [int(x) for x in input().split()]
    # count all numbers in drawings
    for num in draw:
        if num in nums:
            nums[num] = nums[num] + 1
        else:
            nums[num] = 1

# check which ones appear greater than 20% of the time ie 2 * n
for key, value in nums.items():
    if value > ERR:
       ans.append(key)

ans.sort()

if ans:
    print(*ans)
else:
    print(-1)
    # for a in ans:
        # print(a, end=' ')


    




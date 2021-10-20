n, e = input().split()
num = int(n)
e = str(2 ** int(e))
ans = 0
for i in range(num+1):
    b = str(i)
    if e in b:
        ans += 1
print(ans)

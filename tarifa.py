#Python version test

x = int(input())
n = int(input())
ans = x
for i in range(n):
    temp = int(input())
    ans = ans - temp
    ans = ans + x
print(ans)

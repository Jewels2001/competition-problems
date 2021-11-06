t = input()
for i in range(int(t)):
    a = input()
    ans = 0
    for j in range(len(a)):
        str1 = a[:j+1]
        b = bin(int(str1))
        ans2 = 0
        for k in range(len(b)):
            if (b[k]=='1'):
                ans2 += 1
        ans = max(ans, ans2)
    print(ans)

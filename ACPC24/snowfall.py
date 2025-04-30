n = input()
n = int(n)

snow = 0

for i in range(0, n):
    t, a = input().split()
    t = int(t)
    a = int(a)
    
    if t:
        snow = snow - a
        if snow < 0:
            snow = 0
    else:
        snow = snow + a 
        
print(snow)
    
    
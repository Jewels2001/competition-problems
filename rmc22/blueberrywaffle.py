f,r = input().split()
print(("up", "down")[int(f)%int(r) == 0])
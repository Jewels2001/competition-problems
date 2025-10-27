
n = int(input())

jumps = []

dists = input().split()



for d in dists:
    jumps.append(int(d))

first = int(jumps[0] / 3)
last = int(jumps[-1] / 3)

second = int(jumps[1] - first - first)

#for j in jumps[1:-2]:
#
#    temp = j - first - last
#    if temp != first and temp != last:
#        second = temp
#        break
print(first, second, last)




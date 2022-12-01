import sys
total = 0
amounts = []
for a in sys.stdin:
    print()
    if a == "\n":
        print("newline")
        amounts.append(total)
        total = 0
    else:
        total = total + int(a)

amounts.sort(reverse=True)
print(amounts)
print("end")
# Day 1
print(max(amounts))
print(amounts[0], amounts[1], amounts[2])
# Day 2
print(amounts[0] + amounts[1] + amounts[2])
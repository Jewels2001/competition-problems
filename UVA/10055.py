from sys import stdin

for line in stdin:
    a, b = line.split()
    print(abs(int(a)-int(b)))

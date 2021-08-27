day, n = input().split()
n = int(n)
if (day == "DEC" and n == 25) or (day == "OCT" and n == 31):
    print("yup")
else:
    print("nope")

# Python program to find the point of
# intersection of two lines
 
# Class used to  used to store the X and Y
# coordinates of a point respectively
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
 
    # Method used to display X and Y coordinates
    # of a point
    def displayPoint(self, p):
        print(f"({p.x}, {p.y})")
 
 
def lineLineIntersection(A, B, C, D):
    # Line AB represented as a1x + b1y = c1
    a1 = B.y - A.y
    b1 = A.x - B.x
    c1 = a1*(A.x) + b1*(A.y)
 
    # Line CD represented as a2x + b2y = c2
    a2 = D.y - C.y
    b2 = C.x - D.x
    c2 = a2*(C.x) + b2*(C.y)
 
    determinant = a1*b2 - a2*b1
 
    if (determinant == 0):
        # The lines are parallel. This is simplified
        # by returning a pair of FLT_MAX
        return Point(10**9, 10**9)
    else:
        x = (b2*c1 - b1*c2)/determinant
        y = (a1*c2 - a2*c1)/determinant
        return Point(x, y)







n = int(input())
closest = 101

A1 = Point(0, 0)
A2 = Point(0, 100)


for i in range(0, n):
    nums = input().split()
    x1 = int(nums[0])
    y1 = int(nums[1])
    x2 = int(nums[2])
    y2 = int(nums[3])
    b1 = Point(x1, y1)
    b2 = Point(x2, y2)

    intersection = lineLineIntersection(A1,A2, b1, b2)

    # if x is 0 AND y is between 0-100 inclusive, then barrier may be in way
    # then check if intersection is on barrier or is in invisible space
    if intersection.x == 0 and (intersection.y >= 0 and intersection.y <= 100):
        if (intersection.x >= min(x1, x2) and (intersection.x <= max(x1, x2)) and (intersection.y >= min(y1, y2) and intersection.y <= max(y1, y2))):
            # Only reassign closest if it is smaller than the current closest barrier
            closest = min(intersection.y, closest)
    #print(f'({intersection.x},{intersection.y})')

print(closest) if (closest < 101) else print(-1.0) 

    
    #print(f'({x1},{y1})  ({x2},{y2})')
    # 

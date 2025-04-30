
N, S, M = [int(x) for x in input().split(" ")]

list_d = [int(x) for x in input().split(" ")]
 

def f(mid):
    """
    will return true or false 
    Given a decibel level, can we satisfy that decibel level?
    True = Yes, we can
    """
    group_len = 0
    num_groups = 0
    for decibel in list_d:
        if decibel >= mid:
            group_len = group_len + 1
            if group_len == S:
                num_groups += 1
                group_len = 0
            if num_groups == M:
                return True
        else:
            group_len = 0
    return False
        
        
# binary search (bsta - binary search the answer)
## starts in the middle
## checks function on middle
## if true - go one way, else is the other way
## start again from half/middle of that space

hi = int(1e9)
lo = 0
# lo is lowest still valid value / hi is highest one past
while (hi - lo) > 1:
    mid = (hi + lo) // 2
    # true will be that Yes, we can satisfy this level
    if f(mid):
        lo = mid
    else:
        hi = mid


print(lo)

    
    


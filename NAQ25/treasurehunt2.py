
ans_i = 1
ans_j = 1

print("? 2 2", flush=True)
res = int(input())
if not res:
    print("? 4 2", flush=True)
    res1 = int(input())
    if not res1:
        print("? 2 4", flush=True)
        res2 = int(input())
        if not res2:
            print("? 5 4",flush=True)
            res3 = int(input())
            if not res3:
                print("? 3 3", flush= True)
                res4 = int(input())
                if not res4:
                    print("! 3 4", flush=True)
                    exit()
                else:
                    print("! 3 3", flush=True)
            else:
                print("? 5 5", flush=True)
                res4 = int(input())
                if not res4:
                    print("! 4 3", flush=True)
                    exit()
                else:
                    print("! 4 4", flush=True)
                    exit()
        else:
            print("? 2 3",flush=True)
            res3 = int(input())
            if not res3:
                print("? 1 5", flush=True)
                res4 = int(input())
                if not res4:
                    print("! 2 4", flush=True)
                else:
                    print("! 1 4", flush=True)
            else:
                print("? 1 4", flush=True)
                res4 = int(input())
                if not res4:
                    print("! 2 3", flush=True)
                else:
                    print("! 1 3", flush=True)
    else:
        print("? 4 1", flush=True)
        res3 = int(input())
        if not res3:
            print("? 3 3", flush=True)
            res4 = int(input())
            if not res4:
                print("! 4 2", flush=True)
            else:
                print("! 3 2", flush=True)
        else:
            print("? 3 1", flush=True)
            res4 = int(input())
            if not res4:
                print("! 4 1", flush=True)
            else:
                print("! 3 1", flush=True)
else:
    print("? 2 1", flush=True)
    res2 = int(input())
    if not res2:
        print("? 1 3", flush=True)
        res3 = int(input())
        if not res3:
            print("! 2 2", flush=True)
        else:
            print("! 1 2", flush=True)
    else:
        print("? 1 1", flush=True)
        res3 = int(input())
        if not res3:
            print("! 2 1", flush=True)
        else:
            print("! 1 1", flush=True)







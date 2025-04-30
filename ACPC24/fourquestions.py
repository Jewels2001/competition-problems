import sys

found_ans = 0

while not found_ans:
    
    num_to_try = 43
    
    print(f'q {num_to_try}')
    sys.stdout.flush()
    remainder = input()
    remainder = int(remainder)
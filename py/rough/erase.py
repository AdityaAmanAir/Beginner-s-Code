import math

def is_prime(n):
    if n< 2:
        return False
    if n% 2 == 0:
        return n == 2  
    r = int(math.sqrt(n))
    for i in range(3, r+1, 2):
        if n % i == 0:
            return False
    return True

t = int(input())
for j in range(t):
    a, b = map(int, input().split())
    if b==2 and a==1:
        print("YES")
    else:    
        if b == 1 and is_prime(a):
            print("YES")
        else:
            print("NO")

# python program to print first n prime numbers.

def is_prime(p:int) ->bool :
    for _ in range(2,p//2+1):
        if(p%_==0):
            return False
    return True

n=int(input("Enter the Nth number : "))
num=2
while n>0:
    if(is_prime(num)):
        print(num)
        n-=1
    num+=1    
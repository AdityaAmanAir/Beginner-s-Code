# python program to print list of numbers using range and for loop.

n=int(input("Enter the opening Range (Inclusive) :  "))
k=int(input("Enter the Closing Range (non-Inclusive) :  "))
l=int(input("Enter the difference between the range : "))
for _ in range(n,k,l):
    print(_,end=" ")
#Write a program to calculate the square root of a number. Demonstrate the use of break and continue statements.  
a=int(input())
y=1
f=True
while(f):
    if (a<0):
        print("Negative Number")
        break
    else:    
        print("The square root is", a**(1/2))
        f=not(f)
        continue
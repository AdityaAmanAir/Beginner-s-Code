#Write a program to find whether the given number is an Armstrong number.
a=(input())
l=len(a)
i=l
b=int(a)
c=b
sum=0
while i>0:
    i-=1
    f=c%10
    c//=10
    sum+=(f**l)

if(sum==b):
    print("Yes, An Armstrong number")
else:
    print("Not an Armstrong number")    

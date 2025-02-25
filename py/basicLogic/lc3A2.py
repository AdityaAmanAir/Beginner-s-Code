#Write a program to enter a decimal number. Calculate and display the binary equivalent of this number.
a=float(input())
b=int(a)
c=a-b
i=0
pro=0
while b>0:
    d=b%2
    pro+=((10**i)*d)
    b//=2
    i+=1
y=""
j=0
while c>0 and j<16:
    c*=2
    t= int(c)
    y+=str(t)
    c-=t
    j+=1
 
print(pro,y,sep=".")
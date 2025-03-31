#Write the Python Program to Find LCM of two numbers.

a= 2  
b= 45 

i=[]
j=[]
q=[]
LCM=1
x=2
while x<=a:
    if a%x==0:
        i.append(x)
        a/=x
    else:
        x+=1 
x=2           
while x<=b:
    if b%x==0:
        j.append(x)
        b/=x
    else:
        x+=1
i.extend(j)
k=set(i)
for x in k:
    LCM*=x
print(i,k,j,F"LCM is",LCM)    

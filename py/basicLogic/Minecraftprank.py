a=int(input())
b=int(input())
m=b
sum=0
while b : 
    C = input()
    if (b!=m) and (b!=0):
        n=C.count("X")
        n=n-2
        sum+=n
    #grid+=c +"\n"
    b=b-1    
print(sum)
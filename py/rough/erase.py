a=int(input())
while(a>0):
    a-=1
    b=int(input())
    c=2*b
    x=[]
    while(c>0):
        c-=1
        m=int(input())
        x.append(m)
    x.sort()
    j=0
    i=1
    while i <len(x)-1:
            if x[i]-x[i-1]==x[i+1]-x[i]:
                print("No")
                j=1
                break
            i+=1
        
    if(j==0) :
        print("YES")      


    
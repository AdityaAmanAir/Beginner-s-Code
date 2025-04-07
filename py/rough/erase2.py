def coinf(c,l,r):
    first=c[l] 
    second=c[l+1]
    x=0
    cf=0
    cs=0
    for i in range(len(c)+1):
        x+=1
        if x>=l and x<=r:
            if c[i]==first:
                cf+=1
            if c[i]==second:
                cs+=1    
    cl=r-l+1-cf-cs
    print(cl+cf)

coin=input()
c=[]
for i in coin:
    c.append(i)
t=int(input())
for i in range(t):
    l,r=map(int, input().split())
    coinf(c,l,r)
    
    



t=int(input())
while(t>0):
    t-=1
    a=[]
    aa=a.copy()
    an=int(input())
    n=an
    max=0
    plus=0
    if an>3:
        while(an>0):
            an-=1
            x=int(input())
            a.append(x)
        aa.sort()
        max=aa[-1]
        if (max==a[0] or max==a[-1]):
            cor=True
        plus=int(n/2)   
        max+=plus
    while(an>0):
            an-=1
            x=int(input())
            a.append(x)   


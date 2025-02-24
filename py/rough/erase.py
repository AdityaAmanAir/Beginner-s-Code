t=int(input())
while(t>0):
    t-=1
    s=str(input())
    d=(s[::2])
    e=(s[1::2])
    print(e,d)
    f="lol"
    g="noob"
    print(f[2]+g[3])
    for i in range(0,len(s)):
        if(i%2!=0):
            x=f+e[i]
        # else:
        #     f=f+d[i]     
print(f)
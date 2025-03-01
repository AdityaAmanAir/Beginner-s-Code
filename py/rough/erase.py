a=int(input())
while(a>0):
    a-=1
    s=str(input())
    n=len(s)
    d=""
    for i in range(0,n-2):
      d=d+str(s[i])
    print(d+"i")
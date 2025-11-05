a=[[1,2,3],
   [4,5,6],
   [7,8,9]]
b=[[2,5,6],
   [7,8,9],
   [1,2,3]]

n=len(a[0])
m=len(b)
c=[]
var=0

if n==m:
    for i in range (0,n):
        for j in range(0,m):
            a[i][j]=a[i][j]+b[i][j]
    print(a)        
else:
    print("order Does not match")
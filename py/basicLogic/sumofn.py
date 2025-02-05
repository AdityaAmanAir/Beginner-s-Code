n=int(input("Enter the number :"))
q=n
m=n+5
print(id(n),id(m))
sum =0
for i in range(0,q+1,1):
    sum+=i
print(sum)    
n=+1
print(n,m)
print(id(n),id(m))
j=1
sum2=0
while j<=q:
    sum2+=j
    j+=1
print(sum2)    
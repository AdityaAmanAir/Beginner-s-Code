n=int(input("Enter a number :"))
pro=1
for i in range(n,0,-1):
    pro*=i
print(pro)    

# verify
j=1
pro2=1
while j<=n:
    pro2*=j
    j+=1
print("Verified result :",pro2)
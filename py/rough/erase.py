fact=1
num=int(input("enter the number"))
if num==0:
    print(1)
elif num<0:
    print("not possible")
if num>0:
    for i in range(1,num+1):
        fact=fact*i
        print(fact, end=' ')
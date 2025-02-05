def fact(num):
    pro=1
    for i in range(1,num+1):
        pro*=i
    return pro       

num=int(input("Enter the number :"))
fact= fact(num)
print(fact)
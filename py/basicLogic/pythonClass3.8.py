n=int(input("Enter the Number for which you want to write the table : "))
t=int(input("Table till what iteration ? : "))

for i in range(1,t+1,1):
    print(n,"X",i,"=",n*i)
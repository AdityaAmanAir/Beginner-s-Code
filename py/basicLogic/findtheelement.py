num=(1,4,9,16,25,36,49,64,81,100,64)
print(num[3])
n=int(input("Which Number You need to search? "))
t=len(num)
i=0
while t:
    if num[i] == n:
        print("The index of the number in the list is at ",i )
        i+=1
        t-=1
    else:
        i+=1
        t-=1

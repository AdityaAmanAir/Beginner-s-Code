sum=0
numbers =[2,3,5]
for i in range (1,21,1):
    if i%numbers[0]!=0 and i%numbers[1]!=0 and i%numbers[2]!=0 :
        sum+=i
print(sum)        
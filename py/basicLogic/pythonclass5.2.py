nums=[]

while True:
    a=(input("Enter the integer(s) or enter 'quit' if done : "))
    if a.lower()=="quit":
        break
    else:
        nums.append(int(a))#error handeling can be done heretry and catch

print("Total number of items in the list : ", len(nums))
print("The lastitem in the list is", nums[-1])
print("The list in reverse order is",nums[len(nums)-1::-1])
for i in nums :
    if i==5 :
        print("yes" )
        break
    else :
        print("No")
count=0        
for i in nums :
    if i==5 :
        count5+=1
        





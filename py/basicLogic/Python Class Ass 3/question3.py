mylist=[]
num=0
num5=0
lessof5=0
great1=-999999999999
great2=-999999999999
small1=999999999999
small2=999999999999
even=0
sum=0
while True:
    a=input("Enter your list of int or Enter ' ' to exit  : ")
    b=a.lower()
    if b == "" or b == " ":
        break
    mylist.append(int(a))
    num+=1
    if a=="5":
        num5+=1
    if int(a)%2==0:
        even+=1
    if int(a)<small1:
        small2=small1
        small1=int(a)   
    if int(a)>great1:
        great2=great1
        great1=int(a)
    if int(a)<5:
        lessof5 +=1
    sum+=int(a)           

print("The total number of item in the list :", num)
print("Last item is", mylist[num-1])
print("List in reverse order : ", mylist[-1::-1])
print("yes" if 5 in mylist else "No")
print("Number of Fives :",num5)
mylist=mylist[1:num-1]
print(mylist)
for i in range(0,num-2):
    for j in range(1,num-2):
        if mylist[j-1]>mylist[j]:
            temp=mylist[j]
            mylist[j]=mylist[j-1]
            mylist[j-1]=temp

print(mylist)  

print("Number of Int which are less then 5 : ")
print("The average of the elements are :", sum/num)
print(f"The largest vale in the list is {great1} and the smallest is {small1}")
print(f"The second largest value in the list is {great2} and the second smallest is {small2}")
print("The total number of EVEN numbers in the list is ", even)

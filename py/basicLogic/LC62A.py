#Write a program to create two lists and concatenate them into a single list.

list1= [1,2,3,4]
list2= [5,6,7,8]
EmptyList=[]

for i in list1:
    EmptyList.append(i)

for i in list2:
    EmptyList.append(i)

print(EmptyList)    
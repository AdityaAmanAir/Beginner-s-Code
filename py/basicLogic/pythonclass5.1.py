mylist=[]
for i in range(1,101):
    mylist.append(i)

print(mylist)    

len=100
while len>0:
    len-=1
    mylist.pop(len)
print(mylist)    
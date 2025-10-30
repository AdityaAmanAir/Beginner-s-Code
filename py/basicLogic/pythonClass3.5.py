myTupple=(1,4,9,16,25,36,49,64,81,100)
a=int(input("Enter a number which you want to search in the tupple : "))
flag = True
i =0
while i<len(myTupple):
    if(myTupple[i]==a):
        print("Yes! it's their")
        flag=False
    i+=1
if(flag):
    print("No, it's not their")        
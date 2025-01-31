list1=[1,2,3,3,5,2,1]
list2=list1 #this is a wrong way , if we change the vale of list1 in the future , dispite of not making list2=list1 the vale will get updated because list2 is pointing towards list1 !!
list1.reverse()
if list1== list2:
    print("yes")
else:
    print("no")

    # use  new_list = listName.copy()

    #we can short list but not tuple , TUPLE cannot be modified !
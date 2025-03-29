#Tuple and its Operations TASK 1 (A TO J)

Mytuple=(10,20,30)
print(Mytuple)

print(Mytuple[1])

NewTuple=(40,50)
combindTuple=Mytuple + NewTuple
print(combindTuple)

a,b,c,d,e=combindTuple  #this is called Unpacking 
print(a,b,c,d,e)

print(combindTuple.index(30))

print(combindTuple.count(20))

MyList=list(combindTuple)
print(MyList)

print("40 is in Combinde tuple :",40 in combindTuple)

sliced_tuple=tuple(range(1,5))
print(sliced_tuple)

multiple_tuple=[]
for i in Mytuple:
    multiple_tuple.append(i*3)
print(tuple(multiple_tuple))
# Write a program that concatenates two tuples and prints the result.
# Solutions:
# Simple Concatenation Using the + Operator
# Using Tuple Packing and Tuple Unpacking
# Using for loop 
# Convert the tuple into the list and use extend()
# Using functions (or) Recursive Functions

def tupleConc(a,b):
    Mytuple=a+b
    print(Mytuple)

def recTupleConc(a,b):
    if not b:
        return a
    return recTupleConc(a+(b[0],),b[1:])

tuple1=(1,2,3,4)
tuple2=(5,6,"Aditya",3.1415926)

Opt_concatenated_Tuple=tuple1+tuple2
print(Opt_concatenated_Tuple)

a,b,c,d=tuple1
e,f,g,h=tuple2
pack_concatenated_tuple=(a,b,c,d,e,f,g,h)
print(pack_concatenated_tuple)

loop_concatenated_tuple=[]
for i in tuple1:
    loop_concatenated_tuple.append(i)
for i in tuple2:
    loop_concatenated_tuple.append(i)   
print(tuple(loop_concatenated_tuple))  

list1=list(tuple1)
list2=list(tuple2)
list1.extend(list2)
print(tuple(list1))

tupleConc(tuple1, tuple2) #Normal Function
print(recTupleConc(tuple1, tuple2)) #recursion 
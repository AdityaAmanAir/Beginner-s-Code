 #Write a program that uses nested tuples.
# Creating a Nested Tuple
# Accessing elements in a nested tuple - Access the First tuple, Access the Second element in the second tuple
# Iterating through a nested tuple
# Nested tuple unpacking
# Slicing a nested tuple - Slice the Third tuple
# Create two nested tuples and combine in to one
# Comparing nested tuples
# Searching in a nested tuple
# Reversing a nested tuple 

nestedTuple=(("Aditya","Aman",("VIT",417)),("Problem Solving","AVR"),(10,20,30),(1.1,2.00,3.1415926))

print(nestedTuple[0])
print(nestedTuple[1][1])

def fun(mytuple):
    for i in mytuple:
        if isinstance(i,tuple):
            fun(i)
        else:
            print(i)       

def fun2(mytuple):
    a=[]
    for i in mytuple:
        if isinstance(i,tuple):
            fun(i)
        else:
            print(i) 
            a.append(i) 
    print(a)             
    return (a)             


fun(nestedTuple)   
(a,b,(c,d)),(e,f),(g,h,i),(j,k,l)=nestedTuple   
print(a,b,c,d,e,f,g,h,i,j,k,l) 

print(nestedTuple[2][0:2])

nestedtuple2=((1,2,3,(4,5,(6,7),8,9,10,(11,12)),13,14))

newTuple=nestedTuple+nestedtuple2
print(newTuple)

print(nestedTuple==nestedtuple2)

print("--------------------------")

nestedlist=list(nestedTuple)
print("AVR" in fun2(nestedTuple) )


print("--------------------------")
print(nestedTuple[::-1][::-1][::-1])
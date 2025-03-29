#Create a nested tuple
nested_tuple = ((10, 20, 30, 40), ('x', 'y', 'z'), (1.1, 2.2, 3.3, 4.4, 5.5))

#Write a Python expression to extract the last two elements of the first tuple inside nested_tuple using slicing.
print(nested_tuple[0][-2:])

#Retrieve every alternate element from the third tuple.
print(nested_tuple[2][::2])

#Get the last two elements of any every inner tuple, regardless of its length.
nest_list=[]
for i in nested_tuple[::1][-2]:
    nest_list.append(i)
print(nest_list[-2][0:2:1])

#Output of the given slice operation:
result = nested_tuple[1:][0][:-1]
print(result)

#Extract 30 from a nested tuple:
print(nested_tuple[0][2])

#Create a nested tuple
nested_tuple = ((10, (20, 30), 40), ('x', 'y', 'z'), (1.1, 2.2, 3.3, 4.4, 5.5))

#Extract 30 from a nested tuple:
print(nested_tuple[0][1][1])

#Iterate the elements of the nested tuple using for loop
nested_tuple = ((10, (20, 30), 40), ('x', 'y', 'z'), (1.1, 2.2, 3.3, 4.4, 5.5))
def fun(nested_tuple):  
    for i in nested_tuple:
        if isinstance(i, tuple):
            fun(i)
        else:
            print(i)
fun(nested_tuple)     

for i in nested_tuple:
    print(i)

def fun2(nested_tuple):  
    for i in nested_tuple:
        print("OUTER TUPLE:", i)
        if isinstance(i, tuple):
            fun2(i)
        else:
            print("INNER ELEMENT:", i)
fun2(nested_tuple) 






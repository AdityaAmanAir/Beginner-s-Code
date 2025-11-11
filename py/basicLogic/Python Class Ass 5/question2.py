my_tuple = (1, 2, 3, 4, 5)

print("Original tuple:", my_tuple)
print("First element:", my_tuple[0])
print("Last element:", my_tuple[-1])
print("Sliced tuple:", my_tuple[1:4])
print("Length of tuple:", len(my_tuple))
print("Is 3 in tuple?", 3 in my_tuple)
print("Is 7 in tuple?", 7 in my_tuple)
print("Index of 4:", my_tuple.index(4))
print("Count of 2:", my_tuple.count(2))

tuple1 = (1, 2, 3)
tuple2 = (4, 5, 6)
concatenated = tuple1 + tuple2
print("Concatenated tuple:", concatenated)
repeated = tuple1 * 3
print("Repeated tuple:", repeated)
nested_tuple = (1, (2, 3), [4, 5])
print("Nested tuple:", nested_tuple)
a, b, c = tuple1
print("Unpacked values:", a, b, c)
single_element_tuple = (42,)
print("Single element tuple:", single_element_tuple)
tuple_from_list = tuple([10, 20, 30])
print("Tuple from list:", tuple_from_list)

for item in my_tuple:
    print("Item:", item)
if 3 in my_tuple:
    print("3 is present in the tuple")

max_val = max(my_tuple)
min_val = min(my_tuple)
print("Maximum value:", max_val)
print("Minimum value:", min_val)
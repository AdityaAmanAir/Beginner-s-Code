my_list = [10, 20, 30]  # An iterable
my_iterator = iter(my_list) # Get an iterator from the list

print(my_iterator) #list_iterator object at thss memory address

print(next(my_iterator))  # Output: 10
print(next(my_iterator))  # Output: 20
print(next(my_iterator))  # Output: 30

    # Trying to get the next element after exhaustion will raise StopIteration
    # print(next(my_iterator))
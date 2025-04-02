#Create a set my_set, which contains the elements 1 to 5. Create using both the syntax {} and set()
my_set={1,2,3,4,5}
my_set2=set([6,7,8,9,0,7,9,8])
print(my_set)
print(my_set2)

#Create a set my_set1 which contains the mixed type of elements 1, 2.5 and Python. Create using both the syntax

my_set1={1,2.5,"python"}
my_set2=set([1,2.5,"python"])
print(my_set1)
print(my_set2)

#Create an empty set
s1=set()
print(s1)

# Adds a single element - add()
s1=set()
s1.add(5)
print(s1)

# update() - Removes duplicate elements
#update() updates the set, and if any duplicate elements are present, it will be removed
set1 = {1, 2, 3}
set2 = {3, 4, 5}
set1.update(set2)
print(set1)

# Removes 6 from set1 - remove()
#if the element is found, it will be removed otherwise, we will get key error
set1={1,2,3,4,5}
#set1.remove(6)
print(set1)

set1.add(6)
print(set1)
set1.remove(6)
print(set1)

# discard() - Removes 6 if present; does nothing if not found
set1.discard(6)
print(set1)

# pop() - Removes and returns an arbitrary element
set1.pop()
print(set1)

print("-------------------SET OPERATION")

# union() - joins two sets
#Duplicate elements will be removed
set1 = {1, 2, 3}
set2 = {3, 4, 5}
union_set = set1.union(set2)
print(union_set)

# intersection() - Set Intersection
intersection_set=set1.intersection(set2)
print(intersection_set)

# Symmetric Difference - symmetric_difference()

symmetricSet=set1.symmetric_difference(set2)
print(symmetricSet)

#Set Difference - difference()
difference_Set=set1.difference(set2)
print(difference_Set)

# Subset and Superset
set1 = {1, 2}
set2 = {1, 2, 3, 4}
print(set1.issubset(set2))
print(set2.issuperset(set1))

set1 = {1, 2, 5}
set2 = {1, 2, 3, 4}
print(set1.issubset(set2))
print(set2.issuperset(set1))

print("-------------------")
# Check Membership
set1 = {1, 2, 3, 4}
print(2 in set1)      		#True
print(2 not in set1)      	#False
print(10 in set1)     		#False
print(10 not in set1)  	#True

print("-------------------")

#Clearing a set
set1={1,2,3,4}
print(set1)       #{1,2,3,4}
set1.clear()
print(set1)  	#set()

print("-------------------")

#Copying a set
s1={1,2,3,4,5}
print(s1)  #{1, 2, 3, 4, 5}
s2 = s1.copy()
print(s2)  #{1, 2, 3, 4, 5}

print("-------------------")

#length of the set
s1={1,2,3,4,5}
print(len(s1))

print("-------------------")

# isdisjoint()-Returns True if two sets have null intersection
set1 = {1, 2}
set2 = {1, 2, 3, 4}
print(set1.isdisjoint(set2))

set1 = {5,6,7,8}
set2 = {1,2,3,4}
print(set1.isdisjoint(set2))

print("-------------------all()")

# all() - Returns True if all the elements are true 
set1 = {5,6,7,8}
print(all(set1))

set1 = {0,5,6,7,8}
print(all(set1))

print("-------------------any ()")

# any() - Returns True if any of the elements are true
set1 = {5,6,7,8}
print(any(set1))
set1 = {0,5,6,7,8}
print(any(set1))

print("-------------------max and min")

# max()
set1 = {0,5,6,7,8}
print(max(set1))
# min()
print(min(set1))

print("-------------------")

# sorted() - returns a new list, not a set.
my_set = {5, 1, 4, 3, 2}
print(my_set)
sorted_list = sorted(my_set)
print("Sorted List:", sorted_list) 

print("-------------------")

# sum()
set1 = {1, 3, 5}
print(sum(set1))

print("-------------------")
# enumerate() - Returns an enumerate object that contains index and value of the set as a pair
set1 = {1, 3, 5} 
for i in enumerate(set1):	
  print(i)
# (0, 1)
# (1, 3)
# (2, 5)

# Sets in Python are unordered collections, so their elements don't have a fixed position.


# When you print or access the set, the order may be different from how you defined it.
my_set = {5, 1, 4, 3, 2}
print(my_set)

# If you need elements in a specific order, you can use sorted() - returns a new list, not a set.
my_set = {5, 1, 4, 3, 2}
sorted_list = sorted(my_set)
print("Sorted List:", sorted_list)
#Sorted List: [1, 2, 3, 4, 5]




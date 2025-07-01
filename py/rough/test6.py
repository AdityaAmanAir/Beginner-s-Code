set1 = {1, 2}
set2 = {1, 2, 3, 4}
print(set1.issubset(set2))
print(set2.issuperset(set1))

set1 = {1, 2, 5}
set2 = {1, 2, 3, 4}
set1 = {0,5,6,7,8}
print(any(set1))
set1 = {0,5,6,7,8}
print(all(set1))
my_set = {5, 1, 4, 3, 2}
sorted_list = sorted(my_set)
print("Sorted List:", sorted_list) 
set1 = {1, 3, 5} 
for i in enumerate(set1):	
  print(i)
print(enumerate(set1))
a={1:'ONE',2:'two'}
print(a)
a.setdefault(3,"three") 
print(a)
student = {"name": "Alice", "age": 21}
a.setdefault("age", 25)
print(student)  # Output: 21 (does not change)
students = {
    "Alice": {"Math": 90, "Sci": 85},
    "Bob": {"Math": 80, "Sci": 88}
}

print(students["Alice"]["Math"])

# Tuple
t = (1, 2, 3)
print(t[1])
# List
l = [1, 2, 3]
l.append(4)
print(l)

# Set
s = {1, 2, 3}
s.sum(4)
print(s)
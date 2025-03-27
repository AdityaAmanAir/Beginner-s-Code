my_list = [10, "Python", 3.14, True]
print(my_list)

numbers = [1, 2, 3, 4, 5]
print(numbers)

empty_list = list()
print(empty_list)

letters = list("Python")
print(letters)

fruits = ["apple", "banana", "cherry"]

print(fruits[0]) 

print(fruits[-1])

numbers = [10, 20, 30, 40, 50]

print(numbers[1:4])   
# Output: [20, 30, 40]

print(numbers[:3])    
# Output: [10, 20, 30]

print(numbers[::2])   
# Output: [10, 30, 50] (every second element)

fruits = ["apple", "banana", "cherry"]
fruits[1] = "grape"  
print(fruits) 
#['apple', 'grape', 'cherry']

fruits = ["apple", "banana", "cherry"]
print(fruits)
#['apple', 'banana', 'cherry']

fruits.append("orange") 
print(fruits)
#['apple', 'banana', 'cherry', 'orange']

fruits.insert(1, "kiwi") 
print(fruits)
#['apple', 'kiwi', 'banana', 'cherry', 'orange']

fruits.extend(["mango", "grape"])  
print(fruits)
#['apple', 'kiwi', 'banana', 'cherry', 'orange', 'mango', 'grape']

#------------------------------------------
print("-------------------------")

fruits = ["apple", "banana", "cherry"]
fruits.remove("banana")  # Removes 'banana'
print(fruits)
['apple', 'cherry']

fruits.pop(1)  # Removes and returns the 3rd element
['apple', 'cherry']

#'cherry'

print(fruits)
del fruits[0] #['apple']

fruits.clear() 
print(fruits) #[]

numbers = [10, 20, 30]
for num in numbers:
    print(num) 

nums = [5, 3, 8, 1, 3]
print(nums.count(3))  # Output: 2
nums.sort()  # [1, 3, 3, 5, 8]
print(nums)
nums.reverse()  # [8, 5, 3, 3, 1]
print(nums)

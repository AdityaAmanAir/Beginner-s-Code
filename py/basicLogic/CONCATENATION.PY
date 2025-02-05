first = "Hello"
second = "World"
result = first + " " + second  # Joining strings
print(result)

#String Repetition
word = "Python"
print(word * 3)

#String Length
s = "Python Programming"
print(len(s))  # Counts characters (including spaces)

#String membership

 ##IN AND NOT IN
text = "Python is fun"
print("Python" in text)  
print("java" in text)

phrase = "Learning Python is cool"
print("difficult" not in phrase)  

print("cool" not in phrase)       

#String Methods 
#Changing Case of a String
text = "Hello Python"
print(text.upper())  
print(text.lower())  
print(text.title())  
print(text.capitalize())  

#Checking Substrings
s = "Python is fun"
print("Python" in s)   
print("Java" in s)   

#String Replace and Split
s = "I like Python"
print(s.replace("Python", "Java"))  
print(s.split())  

s = "I LOL?like?Python"
print(s.replace("Python", "Java"))  
print(s.split("?")) 

#Removing Whitespaces
s = "  Hello Python  "
print(s.strip())  
print(s.lstrip()) 
print(s.rstrip()) 

print("-------------------")

s = "? Hello Py?thon  ?"
print(s.strip('?'))  
print(s.lstrip("?")) 
print(s.rstrip("?")) 

print("-------------------")

#String Formatting (f-strings)
name = "Abcdef"
age = 25
print(f"My name is {name} and I am {age} years old.")

print("-------------------")

#Iterating Over a String
text = "Python"
for char in text:
    print(char)

print("-------------------")

sentence = "Hello, Python!"
print(sentence[0:5]) 

print("-------------------")
print(sentence[7:13]) 


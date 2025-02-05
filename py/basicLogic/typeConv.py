# Type Conversion - Integer to Float
x = 10  
y = float(x)  
print("Integer:", x)
print("Converted to Float:", y)


a = 3.99  
b = int(a) 
print("Float:", a)
print("Converted to Integer:", b)

num = 25
print(type(num))
text = str(num) 
print("Integer:", num)
print("Converted to String:", text)
print("Type of text:", type(text))

print("-------------------")

s = "100"
print(type(s))
num = int(s)  
print("String:", s)
print("Converted to Integer:", num)

print("-------------------")
s = "3.14"
print(type(s))
f = float(s)  
print(type(s))
print("String:", s)
print("Converted to Float:", f)
print("-------------------")

n = 7
c = complex(n)  
print("Integer:", n)
print("Converted to Complex:", c)
print("-------------------")

#Implicit type Conversion
x = 5   # Integer
y = 2.5 # Float
result = x + y  
print("Result:", result)
print("Type of result:", type(result))

print("-------------------")
a= 10
print(id(a)) #  output : 11758280
a=a+5
print(id(a)) # output 11758440


#CONCLUSION NUMBERS ARE IMMUTABLE

x = 20
y = x   # WITH WILL HAVE SAME ID 
print(id(x), id(y))  

x = x + 1  
print(id(x), id(y))  


x = 10 
y = -5
z = x + y
print("z",id(z),"y",id(y),"x",id(x))

a = 3.14 
b = 2.5  
c = a * b

print("a:", a)
print("b:", b)
print("c:", c)

p = 2 + 3j   # j is iota from complex number  
q = 1 - 2j  
r = p + q

print("p:", p)
print("q:", q)
print("r:", r)

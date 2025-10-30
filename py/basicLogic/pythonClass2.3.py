a = int(input("Enter Numbers : "))
b = int(input("Enter Numbers : "))
c = int(input("Enter Numbers : "))

if a>=b and a>=c:
    print(a)
elif  b>=c and b>=a:
    print(b)  
else:
    print(c)
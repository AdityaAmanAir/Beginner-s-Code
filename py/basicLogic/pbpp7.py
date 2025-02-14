#Python program to Calculate the Area of a Triangle (using Heron's formula)
a=float(input("Enter the length of the side of the Triangle "))
b=float(input("Enter the length of the side of the Triangle "))
c=float(input("Enter the length of the side of the Triangle "))
s=(a+b+c)/2
area=(s*(s-a)*(s-b)*(s-c))**(1/2)
print("The area of the Triangle is", area)
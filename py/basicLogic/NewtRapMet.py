import math
x=float(input("Enter the upper limit of x, !NOTE : This code will only works if the inbuild function is strictly increasing (It is) :")) #insert point
iteration = 5 #use if need or go by decimal 
const = x #only used for the the 2nd code
count = 0
while iteration>0:
    y = (x**4)-x-10
    dybydx = (4*(x**3))-1 
    x=(-y/(dybydx)+x)
    iteration-=1
    count+=1
print("The root of the equation, made by", count, "iteration is ",x)    
#----------------
x=const
const=0
count=0
pre=(int(input("Enter the number of decimal place for which you want the square root :")))
while (abs(const-x)>((1/10)**pre)):
    const=x
    y = (x**4)-x-10
    dybydx = (4*(x**3))-1 
    x=(-y/(dybydx)+x)
    count+=1
print("The root of the equation, made by", count, "iteration in the mention decimal place is ",x)  
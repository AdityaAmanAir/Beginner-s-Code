# a program to calculate square root of a number. Demonstrate the use of break and continue statements
while(1):
    a=float(input("Enter Number Between 0 to 999 :"))
    if a>=999:
        break
    if a<0:
        continue
    else:
        print(a**(1/2))        
print("Program Ends")        
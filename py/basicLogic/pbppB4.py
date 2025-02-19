a=float(input("Enter a Number : "))
if a>0:
    if 5<a<10:
        print("Positive even Number")
    else:
        print("Positive odd Number")    
    
elif a<0:
    if a%2==0:
        print("Negative even Number")
    else:
        print("Negative odd Number")    
    
else:  
    print("Number is Zero and it is Even")  
print("Program execution completed")     
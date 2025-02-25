# Write a program to calculate the electricity bill based on the following information

# Consumption Unit
# Rate of Charge
# 0 – 150
# Rs. 5 per unit
# 151 – 350
# Rs.100 plus  Rs. 5.75 per unit exceeding 150 units
# 301 – 450
# Rs.250 plus  Rs. 6 per unit exceeding 350 units
# 451 – 600
# Rs.300 plus  Rs. 6.25 per unit exceeding 450 units
# Above 600
# Rs.400 plus  Rs. 7.00 per unit exceeding 600 units

a=int(input("Enter consumption Unit : "))
if(a<=150):
    print ("Amount :",a*5)
else:
    if(a<=350):
        print ("Amount :",100+(a*5.75))
    elif(a<=450):
        print("Amount :",250+(a*6))
    elif(a<=600):
         print("Amount :",300+(a*6.25))
    else:
        print("Amount :",400+(a*7))     
    

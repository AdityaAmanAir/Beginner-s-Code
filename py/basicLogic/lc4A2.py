# A company decides to give bonus to all employees on Diwali. A 5% bonus on salary is given to the male workers and 10% bonus on salary to the female workers. Write a program to enter the salary of the employee and sex of the employee. Calculate the bonus of the employee.
a=float(input("Enter Your Salary : Rs."))
b=str(input("Enter Your Sex (Male/Female) :"))
b=b.upper()
if b=="MALE":
    print("Your Bonus is : Rs.",a*0.05,sep="")
elif b=='FEMALE':
    print ("Your Bonus is : Rs.",a*0.1,sep="")
else:
    print("Invalid Sex")    
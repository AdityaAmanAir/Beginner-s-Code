# a Program to calculate income tax to be paid by the employee of an organization. (write the condition and write the program)
a=float(input("Enter Salary Before Tax : Rs."))
if a<=400000:
    print("Tax Rs.",0*a,sep='')
elif 400001 <=a<= 800000 :
    print("Tax Rs.", 0.05*a,sep='')  
elif  800001<=a<= 1200000:
    print("Tax Rs.", 0.1*a,sep='')
elif 1200001 <=a<= 1600000:
    print("Tax Rs.", 0.15*a,sep='')
elif 1600001 <=a<= 2000000:
    print("Tax Rs.", 0.2*a,sep='')   
elif 2000001 <=a<= 2400000:
    print("Tax Rs.", 0.25*a,sep='')  
else:
      print("Tax Rs.", 0.3*a,sep='')      
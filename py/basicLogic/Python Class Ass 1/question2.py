unit= float(input("Enter the electric consumed unit : "))
charge=0
if unit <100:
    charge =1.60
elif unit<=200:
    charge = 2.35
elif unit<=400:
    charge =3.40
elif unit>400:
    charge=5.25
print(f"The total amount generated for {unit} unit electricity bill is Rs.{charge*unit} ")         
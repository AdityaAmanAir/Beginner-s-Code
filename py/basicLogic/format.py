a=10
b="Aditya Aman"
print(f"{b} is 10 out of {a}")
print(f"{b} is 10 out of {5}")
print("{0} and {1} sees a cat".format("anjali",'bhumi'))
print("{0} and {1} sees a cat".format("anjali",b))
print("{x} and {y} sees a cat".format(x="anjali",y=b))

c="Aditya Aman is not a good student"
d=c.split(" ")
print(d) #list will be created 

unknown=123.3555
print("The marks is ",format(unknown,"1.1f"))
print("The marks is ",format(unknown,"2.2f"))
print("The marks is ",format(unknown,"10.10f"))
print("The marks is ",format(unknown,"3.3f"))
print("The marks is ",format(unknown,"4.4f"))
print("The marks is ",format(unknown,"10.2f"))
print("The marks is ",format(unknown,"2.10f"))

#"2.2f" → Minimum width = 2, Precision = 2
#if min width > precision then it will add white space   in the front.
#if min width < precision then it will add zeros at the end of decimal
###NOTE ,{comma} is used here insted of . {full stop}


#C-style string formatting
x=12.3456789
print("The vale of x is %.2f"%x)
print("The vale of x is %.4f"%x)
print("The vale of x is %20.5f" %x)

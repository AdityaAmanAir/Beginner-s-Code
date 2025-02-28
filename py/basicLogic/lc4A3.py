# A program that prompts users to enter a character (o,a,b,c,f). Then using if-elif-else construct display outstanding, very good, good, average and fail respectively.
ch=str(input("Enter a character : "))
if ch=='o':
    print("outstanding")
elif ch=='a':
    print("very good") 
elif ch=='b':
    print("good") 
elif ch=='c':
    print("averaged") 
elif ch=='f':
    print("fail") 
else:
    print("Invalid Input")                   
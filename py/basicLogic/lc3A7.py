#Write a program that prompts users to enter a character (O, A, B, C, F). Then using the if-elif-else construct display Outstanding, Very Good, Good, Average, and Fail respectively.
a=str(input("Enter a character (O, A, B, C, F) : "))
if(a=='O'):
    print("Outstanding")
elif (a=='A'):
    print("Very Good")
elif (a=='B'):
    print("Good")
elif (a=='C'):
    print("Average")   
elif (a=='F'):
    print("Fail")        
else:
    print("Wrong Character")     
#A program to enter any character. If the entered character is in lowercase then convert it into uppercase and if it is an uppercase character, then convert it into lowercase.
ch=str(input("Enter any character : "))
if 'a'<=ch <='z':
    print(ch.upper())
else:
    print(ch.lower())    

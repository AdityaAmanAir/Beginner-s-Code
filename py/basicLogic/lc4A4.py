# A program that prompts the user to enter a string. The program calculates and displays the length of the string until the user enters “Quit”.
while(1):
    s=str(input("Enter a string (\"Quit\" to Exit): "))
    if s=="Quit":
        break
    print("length of String",len(s))
    

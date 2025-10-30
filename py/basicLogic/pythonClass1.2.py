a= int ( input("Enter number students to assign marks : "))
while a:
    a=a-1
    b= int(input(" Enter the marks od the student : "))
    if b>90:
        print("Score = A")
    elif b>80:
        print("Score = B")
    elif b>70:
        print("Score = C")    
    else:
        print("Score = D")    
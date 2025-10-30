a=int(input("Enter How Many Number you want to check : "))

while a:
    a-=1
    b=int(input("Enter the Number : "))
    if b%2==0:
        print("It's Even")
    else:
        print("It's Odd")
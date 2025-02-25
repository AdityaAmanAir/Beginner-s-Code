#Write a program to print a multiplication table of n, where the user enters n.
a=int(input("Enter a Number : "))
for i in range(1,11):
    c=a*i
    print(a,"x",i,"=",c)
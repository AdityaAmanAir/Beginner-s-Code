#Python program to Swap Two Numbers Using XOR
a=int(input("Enter the Number "))
b=int(input("Enter the Number "))
a=a^b #1010 1100
b=a^b #1001 1100
a=a^b #1001 1010 --> 1100
print(a,b)

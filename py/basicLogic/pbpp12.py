#Python program to Convert a Lowercase Letter to Uppercase Using Bitwise Operations
a=(input("Enter the Character : " ))
print(chr(ord(a)& 0b11011111))
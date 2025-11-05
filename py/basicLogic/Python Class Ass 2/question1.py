mystring=input("Enter a word/sentence : ")
i=len(mystring)
b=True
for cha in range(0,i//2 +1):
    if(mystring[cha]!=mystring[i-cha-1]):
        print("Not a palindrome")
        b=False
        break
if(b):
    print("A palindrome")
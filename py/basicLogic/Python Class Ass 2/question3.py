mystring=input("Enter a word/sentence : ")
i=len(mystring)

print(i)
print(mystring*10)
print(mystring[0])
print(mystring[0:3])
print(mystring[-3:])
print(mystring[-1::-1])
print(mystring[6] if i>=7 else print("Error! The string is Small"))
print(mystring[1:i-1])
print(mystring.upper())

for j in mystring: 
    if j!='a' :
        print(j, end="")
    else :
        print("e", end="")
print("\n")
for j in mystring: 
    if j!=' ' :
        print(j, end="")
    else :
        print('-', end="")    
print("\n")           
print(" "*i)         
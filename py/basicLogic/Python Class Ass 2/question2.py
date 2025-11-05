mystring=input("Enter a word/sentence : ")
i=len(mystring)
num=0
alph=0
for item in mystring:
    if ord(item) >=48 and ord(item)<=57:
        num+=1
    elif (ord(item)>=65 and ord(item)<=90 ) or (ord(item)>=97 and ord(item)<=122 ):
        alph+=1
print(f"In this string the number of \n Alphabets : {alph}\n Digits : {num}\n Special Symbols : {i-num-alph}")            
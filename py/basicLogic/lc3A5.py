#Write a program that displays all leap years from 1900-2022.
for n in range(1900,2023):
    if(n%100!=0):
        if(n%4==0):
            print(n,"is Leap Year")
        else:
            pass
    else:
        pass   
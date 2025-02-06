def num(n):
    if(n==1):
        return 1
    else:
        return num(n-1)+n
    

print(num(996))
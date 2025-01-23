a=int(input("Enter the Numbers a, :"))
b=int(input("Enter the Numbers b, :"))
c=int(input("Enter the Numbers c, :"))
if a>b>c or a>c>b:
    print(a,"is the gratest")
elif c>b>a or c>a>b:
    print(c,"is the gratest")    
elif b>a>c or b>c>a:
    print(b,"is the gratest")  
elif a==b==c:
    print("All the numbers are same :",a,b,c)  
elif a==b and b>c:
       print(a ,"is the gratest") 
elif a==c and b<c:
       print(a ,"is the gratest") 
elif b==c and a<c:
       print(c ,"is the gratest")        
elif a==b and b<c:
       print(c ,"is the gratest") 
elif a==c and b>c:
       print(b ,"is the gratest") 
elif b==c and a>c:
       print(a ,"is the gratest") 
else:
      print("WTH, which condition is this?, you are G from Parle-G")                     
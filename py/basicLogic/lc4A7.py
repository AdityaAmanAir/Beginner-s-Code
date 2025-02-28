#A program to read the number until -1 is encountered. Also count the negatives, positives and zeroes entered by the user and calculate the average of positive and negative numbers entered by the user.
sumP=0
countP=0
sumN=0
countN=0
countO=0
while(1):
    a=float(input("Enter A Number (-1 to Terminate) : "))
    if(a==-1):
        break
    if(a>0):
        sumP+=a
        countP+=1
    elif(a==0) :
        countO+=1  
    else:
        sumN-=a
        countN+=1  
print("Number of positive Number :",countP)   
print("Number of negative Number :",countN)  
print("Number of Zero :",countO)        
if countP>0:
    print("The average of positive numbers", sumP/countP)         
if countN>0:
    print("The average of negative numbers", -(sumN/countN))               
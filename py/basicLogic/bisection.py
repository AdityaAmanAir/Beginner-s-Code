import math
xl=int(input("Enter the Lower Limit of X :"))
xu=int(input("Enter the Upper Limit of X :"))
XL=xl
XU=xu
count=0
iteration=int(input("Enter the numnber of Iteration :"))
while iteration:
    count+=1
    iteration-=1
    avg=(xl+xu)/2
    if  (avg**4)-avg-10<0:
        xl=avg
    elif  (avg**4)-avg-10>0:
        xu=avg 
    elif  (avg**4)-avg-10==0:
        print("We found the Exact the root of the equation :", avg ,"and the iteration we had is ", count) 
        break    
print("We found the root of the equation :", avg, "and the iteration we had is ", count)    
#-------------------------
pre=int(input("Enter the number of decimal place for which you want the square root :"))
count2=0
while abs(XU-XL)>((1/10)**pre):
    count2+=1
    iteration-=1
    avg=(XL+XU)/2
    if  (avg**4)-avg-10<0:
        XL=avg
    elif  (avg**4)-avg-10>0:
        XU=avg     
print("We found the root of the equation :", avg, "and the iteration we had is ", count2)

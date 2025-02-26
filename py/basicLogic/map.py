#it is an inbuid function to take all the inputs of same line and map them to correct variable 
#it help us to avoid making loop for every input again and agian

x,y,z=map(int,input("Enter :").split()) #split is important



#split
a="as+asd+sd+sd+sd+d+dss=xd d+dse dk=ddd +d++mdd+++"
d=a.split("+",7) #2nd one is called maxsplit i.e 7 here
e=a.split("+")
print(d)
print(e)

#round
h=3.14125925
print("This is pi", round(h,4)) #we ca use i=build function like this

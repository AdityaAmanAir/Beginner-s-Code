#Write a Python program to find the maximum and minimum values in a list.
# Using a while Loop. Dont use any Built-in functions 

list=[0,54,-38,3,1,1,77,9.6,32,89]
min=999999999999999999999
max=-999999999999999999999
length = len(list)
while length>=0:
    j=length
    if length<=min:
        min=length
    if length>=max:
        max=j 
    length-=1    
print(f'minimun is {min}')       
print(f'maximum is {max}') 
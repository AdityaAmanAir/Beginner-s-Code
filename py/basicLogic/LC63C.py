#Write a Python program to find the maximum and minimum values in a list.
# Using a for Loop. Dont use any Built-in functions 

list=[0,54,-38,3,1,1,77,9.6,32,89]
min=999999999999999999999
max=-999999999999999999999
for i in list:
    j=i
    if i<=min:
        min=i
    if i>=max:
        max=j 
print(f'minimun is {min}')       
print(f'maximum is {max}') 
#Write a program to enter a number and then calculate the sum of its digits.
a=int(input())
sum=0
while a>0:
    c=a%10
    a//=10
    sum+=c
print(sum)    
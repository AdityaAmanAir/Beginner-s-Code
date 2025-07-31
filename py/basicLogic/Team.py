t=int(input())
count=0
while t:
    t-=1
    b,c,a=map(int,(input().split()))
    if (a+b+c >=2):
        count+=1
print(count)        
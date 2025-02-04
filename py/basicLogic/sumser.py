#Find the 11th term and sum
sr=[2,5,8,11,14,17]
sum=0
a=int(input("Give the term : "))
i=a-5
diff=3
g=1
n=sr[5]
while i<a:
    
    n+=3
    (sr.append(n))
    i+=1
print("The seq. is :",sr)
for k in sr:
    sum+=k
print("Sum is :",sum)
mm=len(sr)
ver=[0]
while mm>0:
    ver[g] =(sr[0]+(g-1)*diff)
    g+=1
    mm-=1
print("check sq",ver)
sumver= len(sr)/2*(2*sr[0]+ (len(sr)-1)*diff)
print("verification", sumver)

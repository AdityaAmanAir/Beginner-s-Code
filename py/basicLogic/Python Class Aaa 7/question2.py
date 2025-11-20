n=int(input("Enter the total number of subjects : "))
data=[]
numOf1=0
for _ in range(0,n):
    a=(input("Enter the marks of the subject : "))
    if"1" in a:
        numOf1+=1
    data.append(int(a))
print("Sum = ", sum(data))
print("Avg = ", sum(data)/n)

print("Marks list in reverse order :", data[-1::-1])
print("2nd Last element from the list :", data[-2])
print("Total number of 1's in the list :", numOf1)
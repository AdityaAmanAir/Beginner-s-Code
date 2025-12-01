#python program to multiply matrices.

n1=int(input("Okay Engineer! You want to do Matrix 1 x Matrix 2 haaan?! \n Enter the Number of rows in your 1st matrix :"))
n2=int(input(" Enter the Number of rows in your 1st matrix :"))

m1=int(input(" Enter the Number of Column in your 2nd matrix :"))
m2=int(input(" Enter the Number of Column in your 2nd matrix :"))

if n2!=m1:
   print("Wow! matrices cannot be mutiplied together, You VITen?")
   
else:
    ans=[]
    print("Enter the Matrix 1 together : \n")
    mx1=[]
    for _ in range (0,n1):
        a=input()
        a=list((a.split()))
        mx1.append(a)

    print("Enter the Matrix 2 together : \n")
    mx2=[]    
    for _ in range (0,n2):
        a=input()
        a=list((a.split()))
        mx2.append(a)
    mt1=tuple(mx1)    
    mt2=tuple(mx2)# I did  this because tuple is slightly faster then list

    ansMatrix=[]
    for i in range (0,n1):
        for j in range (0,m1):
            ansMatrix2=[]
            for k in range(0,m2):
                element=int(mt1[i][j])*int(mt2[j][k])
                ansMatrix2.append(element)
            ansMatrix.append(ansMatrix2)

    for i in range(0,n1):
        
    
            a.append(sum2)
        ans.append(a)  

        # print(ansMatrix)

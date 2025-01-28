import math
A=[1,2,3]
B=[1,2,3]

Asq=[A[i]*A[i] for i in range(len(A))]
print("Sq of A Vecter",Asq)

Bsq=[B[i]*B[i] for i in range(len(A))]

modA= ((sum(Asq))**0.5)

print(modA)

modB= ((sum(Bsq))**0.5)

 
ab=[A[i]+B[i] for i in range(len(A))]
print("The sum of all the element in both the arrey :",ab)

ABsq=[ab[i]*ab[i] for i in range(len(A))]

modAB= ((sum(ABsq))**0.5)


print("Mod of A and B vecter",modAB)

dotab=[A[i]*B[i] for i in range(len(A))]

dotABsq=[dotab[i]*dotab[i] for i in range(len(A))]

modAB= ((sum(ABsq))**0.5)
print("Dot :",dotab, dotABsq)





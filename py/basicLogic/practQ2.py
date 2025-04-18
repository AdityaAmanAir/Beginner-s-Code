import numpy as np
V1=[1,2,3]
V2=[4,5,6]

V1= np.array(V1)
V2= np.array(V2)

A=[[1,2,3],
   [2,3,5],
   [1,1,2]]

B=[[2,3,4],
   [2,2,1],
   [4,4,3]]

A= np.array(A)
B= np.array(B)

N=[]
N=np.array(N)
X=[]
X=np.array(X)

N=A.dot(B)
X=V1.dot(V2)

print("Dot product of two vector is\n",X)
print("Product of two (3x3) matrix is\n",N)

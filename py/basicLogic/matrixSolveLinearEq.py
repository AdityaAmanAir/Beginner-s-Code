import numpy as np
a=np.array([[3,1,2],[2,-3,-1],[1,2,1]])
x=np.array([[3],[-3],[4]])
A_inv=np.linalg.inv(a)
c=np.dot(A_inv,x)
print(c)

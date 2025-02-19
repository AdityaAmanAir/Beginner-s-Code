import numpy as np
A=[[1,1,-1],[3,-2,1],[1,3,-2]]
X=[[6],[-5],[14]]
AI= np.linalg.inv(A)
B=AI.dot(X)
print(B)
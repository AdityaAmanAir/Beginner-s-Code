#Triple product of the vectors using numpy

import numpy as np
A=[1,0,0]
B=[0,1,0]
C=[0,0,1]
m= np.array(A)
n= np.array(B)
o= np.array(C)

no= np.cross(n,o)
mno= np.dot(m,no)
print(mno)

A=[1,1,0]
B=[1,1,0]
C=[0,0,1]
m= np.array(A)
n= np.array(B)
o= np.array(C)

no= np.cross(n,o)
mno= np.dot(m,no)
print(mno)

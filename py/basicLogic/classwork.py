import math
import numpy as np

A=[1+2*((7)**(1/2)), 1,2]
B=[1,1.5,2]
C=[1,3,2]

modA=[(sum(A[i]**2 for i in range (len(A))))**(1/2)]

modB=[(sum(B[i]**2 for i in range (len(B))))**(1/2)]



CA= [C[i]-A[i] for i in range (len(A))]
BA= [B[i]-A[i] for i in range (len(A))]

CAB = [BA[i] * CA[i] for i in range(len(A))]


modCAB=[(sum(CAB[i]**2 for i in range (len(A))))**(1/2)]

Theta= math.acos(modCAB/((modA)*(modB)))
heta= np.arccos(modCAB/((modA)*(modB)))

print(Theta,heta)




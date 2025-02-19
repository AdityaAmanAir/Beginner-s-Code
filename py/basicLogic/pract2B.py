import numpy as np
import matplotlib.pyplot as plt
H2=120
W2=90
A2=30

Y2=[]
X2=[]
Y4=[]
X4=[]
H4=90
A4=70
for x2 in range(0,100):
    X2.append(x2)
    y2=0.58*x2 - 0.0064*(x2**2)
    Y2.append(y2)
for x4 in range(0,100):    
    y4=2.75*x4 - 0.0306*(x4**2)
    X4.append(x4)
    Y4.append(y4)
plt.plot(X2,Y2)  
plt.plot(X4,Y4)  

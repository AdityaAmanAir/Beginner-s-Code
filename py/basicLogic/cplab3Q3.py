import math
import matplotlib.pyplot as mp

i=0
A=1
T=[]
X=[]
while(i<=20):
    T.append(i)
    i+=0.001

phi=0
mass=0.25
k=85
b=0.07

w=(k/mass -(b/2*mass)**2)**(1/2)

for t in T:
    l=A*((2.718281828)**(-b*t/(2*mass)))* math.cos(w*t+phi)
    X.append(l)

mp.plot(T,X)    
mp.show()
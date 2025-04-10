import matplotlib.pylab as mp 
import math
Amp=2
w=5**(1/2)
i=0
T=[]
while(i<=10):
    T.append(i)
    i+=0.01

theta =math.radians(0)
Y=[]
for j in T:
    x=Amp*math.sin(w*j + theta)  
    Y.append(x)
mp.plot(T,Y) 

theta =math.radians(10)
Y=[]
for j in T:
    x=Amp*math.sin(w*j + theta)  
    Y.append(x)
mp.plot(T,Y)

theta =math.radians(25)
Y=[]
for j in T:
    x=Amp*math.sin(w*j + theta)  
    Y.append(x)
mp.plot(T,Y)

mp.show()

V=[]
A=[]
theta =math.radians(0)
for k in T:
    l=Amp*w*math.cos(w*k+theta)
    m=-1*Amp*w*w*math.sin(w*k+theta)
    V.append(l)
    A.append(m)
mp.plot(V,A)    

theta =math.radians(10)
for k in T:
    l=Amp*w*math.cos(w*k+theta)
    m=-1*Amp*w*w*math.sin(w*k+theta)
    V.append(l)
    A.append(m)
mp.plot(V,A)  

theta =math.radians(25)
for k in T:
    l=Amp*w*math.cos(w*k+theta)
    m=-1*Amp*w*w*math.sin(w*k+theta)
    V.append(l)
    A.append(m)        
mp.plot(V,A)  
mp.show()   
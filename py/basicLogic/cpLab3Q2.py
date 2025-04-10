import math
import matplotlib.pylab as mp

a=1
n=1

X=[]
i=0
while(i<a):
    X.append(i)
    i+=0.001
  
Y=[]
for j in X:
    l=((2/a)**(1/2))*math.sin((n*math.pi*j)/a)
    Y.append(l)
mp.plot(X,Y) 

n=2
Y=[]
for j in X:
    l=((2/a)**(1/2))*math.sin((n*math.pi*j)/a)
    Y.append(l)
mp.plot(X,Y)

n=3
Y=[]
for j in X:
    l=((2/a)**(1/2))*math.sin((n*math.pi*j)/a)
    Y.append(l)
mp.plot(X,Y)

mp.show()
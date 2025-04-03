import math
import matplotlib.pylab as mp

a=1
b=1
w=1
pi=0
t=[]
x=[]
y=[]
i=0
while i<10:
    i+=0.001
    t.append(i)
    x.append(math.sin(w*i+pi))
    y.append(math.cos(w*i+pi))
mp.plot(t,x)
mp.plot(t,y)
#so x^2+y^2=A^2
mp.grid()
mp.show()    


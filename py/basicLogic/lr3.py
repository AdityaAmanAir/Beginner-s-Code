import matplotlib.pyplot as plt
import math
m=[50,450,780,1200,4400,4800,5300]
o=[28,30,32,36,51,58,69]
k = [math.log(value) for value in o]

n=len(m)
sumx=sum(m)
sumy=sum(k)
xy = [m[i] * k[i] for i in range(len(m))]
sumxy=sum(xy)
xsq = [j**2 for j in m]
sumxsq=sum(xsq)
b = (n*sumxy-sumx*sumy)/(n*sumxsq-sumx**2)
a=(sumy-(b*sumx))/n
A=
print("Value of b",b)
print("Value of a",a)
d = [min(m), max(m)]
e = [a + b * x for x in d]
plt.plot(m,o)
plt.plot(d,e,color='red', linestyle = '-.', label = 'Best Fit Line')
plt.show()
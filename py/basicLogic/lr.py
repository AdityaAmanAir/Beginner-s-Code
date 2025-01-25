import matplotlib.pyplot as plt
m=[6,7,7,8,8,8,9,9,10]
k=[5,5,4,5,4,3,4,3,3]
n=len(m)
sumx=sum(m)
sumy=sum(k)

xy = [m[i] * k[i] for i in range(len(m))]
sumxy=sum(xy)
xsq = [j**2 for j in m]
sumxsq=sum(xsq)
b = (n*sumxy-sumx*sumy)/(n*sumxsq-sumx**2)
a=(sumy-(b*sumx))/n
print("Value of b",b)
print("Value of a",a)
print(sumx, sumy, sumxy, sumxsq)
d = [min(m), max(m)]
e = [a + b * x for x in d]
plt.plot(m,k)
plt.plot(d,e,color='red', linestyle = '-.', label = 'Best Fit Line')
plt.show()

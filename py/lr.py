import matplotlib.pyplot as plt
x=[1,2,3,4]
y=[16,19,23,26]
n=len(x)
sumx=sum(x)
sumy=sum(y)
xy = [x[i] * y[i] for i in range(len(x))]
sumxy=sum(xy)
xsq = [j**2 for j in x]
sumxsq=sum(xsq)
b=(sumxy-(sumx/n))/(sumxsq-(sumx/n))
a=(sumy-(b*sumx))/n
print("Value of b",b)
print("Value of a",a)
plt.plot(x,y)
plt.show()
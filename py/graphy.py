import matplotlib.pyplot as plt
v=0
r=10
X=[]
Y=[]
while v<=20:
  i=v/r
  Y.append(i)
  X.append(v)
  v+=1
plt.plot(X,Y)
plt.show()
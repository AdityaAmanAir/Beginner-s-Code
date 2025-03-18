import matplotlib.pyplot as plt
mass=60
g=9.8
height=100
X=[]
Y=[]
Z=[]
A=[]
V=[]
for i  in range (0,height+1,1):
    X.append(i)
    PE=mass*g*i/1000
    Y.append(PE)
    s=height-i
    KE=mass*g*s/1000
    Z.append(KE)
    TE=PE+KE
    A.append(TE)
    velocity=(2*g*i)**(1/2)
    print(velocity)
    V.append(velocity)

plt.plot(X,A)
plt.plot(X,Y)    
plt.plot(X,Z)
plt.plot(X,V)
plt.show()
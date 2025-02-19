import matplotlib.pyplot as plt
X=[]
Y=[]
for t in range(0,121,5):
    x=-0.31*(t**2)+7.2*t+28
    y=0.22*(t**2)-9.1*t+30
    #print(x,y)
    X.append(x)
    Y.append(y)
    plot(x,y)
plt.plot(X,Y)   
plt.show() 
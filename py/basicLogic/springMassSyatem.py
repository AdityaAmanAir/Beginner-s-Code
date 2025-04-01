import matplotlib.pyplot as mp
import math


mass=680/1000 #int(input("Enter the Mass in gram(s) : "))
spring_constant=65 #int(input("Enter the spring constant in N/m :) : "))
pulled_distance = 11/100
A=11
omega= ((spring_constant/mass)**(1/2))
        
f=omega/(2*(math.pi)) 
T=[]
V=[]
x=-1
while -11/100<=x<=11/100 :
    T.append(x)      
    v=A*omega*math.sin(omega*x)
    V.append(v)
    x+=0.001

mp.plot(T,V) 
mp.grid()   
mp.show()
# A block of mass m= 3.20 kg slides from rest down a frictionless incline at angle 30 0 . After travelling
# d=40cm it
# runs into a spring of spring constant 431 N/m. When the block momentarily stops, it has compressed the
# spring by 21.0 cm.
# Draw the following graph
# a. Distance vs Velocity
# b. Distance vs K.E of the mass

import matplotlib.pyplot as mp
import math
mass= float(input("Enter the mass of block in Kg : "))
D_angle= float(input("Enter the angle (in deg): "))
distance= int(input("Enter the distance traveled  (in cm): "))/100
spring_constant= float(input("Enter the spring Constant (N/m): "))
compOfSpring= int(input("Enter value when the block momentarily stops i.e. compressed spring value (in cm): "))/100

g=9.81
friction=0
inVel=0
angle=math.radians(D_angle)

D=[]
V=[]
KE=[]
for x in range(0, int(distance * 100) + 1, 1):  
    x_m = x / 100  
    velocity = math.sqrt(2 * g * x_m * math.sin(angle))  
    kinetic_energy = 0.5 * mass * velocity**2

    D.append(x_m)
    V.append(velocity)
    KE.append(kinetic_energy)

for x in range(int(distance * 100), int((distance + compOfSpring) * 100) + 1, 1):
    x_m = x / 100  
    compression = x_m - distance  

    
    velocity = math.sqrt(max(0, 2 * (g * distance * math.sin(angle) - 0.5 * spring_constant * compression**2 / mass)))
    kinetic_energy = 0.5 * mass * velocity**2

    D.append(x_m)
    V.append(velocity)
    KE.append(kinetic_energy)

mp.subplot(1, 2, 1)
mp.plot(D, V)

mp.subplot(1, 2, 2)
mp.plot(D, KE)

mp.tight_layout()
mp.show()

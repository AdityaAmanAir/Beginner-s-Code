import numpy as np
import math
#vector
a = np.array([1,1,1])
b = np.array([-1,-1,-1])
#initialize
c=0
d=0
e=0
mod_d=0
mod_e=0
angle1=0
theta1=0
#useing loop
for i in range (3):
    c += a[i]*b[i]
#Mod of vector useing loop
for i in range (3):
    d += a[i]*a[i]
    e += b[i]*b[i]
mod_d=math.sqrt(d)
mod_e=math.sqrt(e)
angle1=c/(mod_d*mod_e)

cos_angle = np.clip(angle1, -1.0, 1.0) # to make the value of angle between +1 to
-1

theta1=math.acos(cos_angle)
degree=math.degrees(theta1)
#print(theta1)
#print("c=",c)
#print(degree)
print(angle1)
print(cos_angle)
print(theta1)
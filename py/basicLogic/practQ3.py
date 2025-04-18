import matplotlib.pyplot as mp
import math
import numpy as np

v0 = 25.0  
theta_deg = 35.0  
g = 9.8  

theta_rad = np.radians(theta_deg)

v0x = v0 * np.cos(theta_rad)
v0y = v0 * np.sin(theta_rad)

t_flight = (v0y + np.sqrt(v0y**2 + 2 * g * 20)) / g 

t = np.linspace(0, t_flight, num=300)

x = v0x * t
y = v0y * t - 0.5 * g * t**2

mp.plot(x, y)
mp.axhline(-20, color='red', linestyle='--')
mp.grid(True)
mp.show()

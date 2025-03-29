import numpy as np
import matplotlib.pyplot as plt

v0 = 6.0
g = 9.8
h = 1.1
mu_k = 0.60

v_frictional_start = np.sqrt(v0**2 - 2 * g * h)
a_friction = -mu_k * g
d = -v_frictional_start**2 / (2 * a_friction)
distances = np.linspace(0, d, 100)
velocities = np.sqrt(v_frictional_start**2 + 2 * a_friction * distances)
plt.plot(distances, velocities)
plt.show()
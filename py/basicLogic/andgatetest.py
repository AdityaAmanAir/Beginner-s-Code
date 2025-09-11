import matplotlib.pyplot as mp
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

x = np.arange(0, 100, 1)
y = np.arange(0, 100, 1)
X, Y = np.meshgrid(x, y)
Z = X & Y

fig = mp.figure()
ax = fig.add_subplot(111, projection='3d')  
ax.plot_surface(X, Y, Z) 

mp.show()
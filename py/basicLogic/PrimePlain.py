import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(np.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Generate prime numbers up to 30 for better performance
primes = [n for n in range(1, 101) if is_prime(n)]

# Create arrays for scatter plot of x*y
x1 = []
y1 = []
z1 = []
# Create arrays for scatter plot of (x-1)*(y-1)
x2 = []
y2 = []
z2 = []
for i in primes:
    for j in primes:
        # For x*y
        x1.append(i)
        y1.append(j)
        z1.append(i * j)
        # For (x-1)*(y-1)
        x2.append(i)
        y2.append(j)
        z2.append((i-1) * (j-1))

# Create 3D scatter plot
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# Plot points for x*y with smaller marker size
ax.scatter(x1, y1, z1, c='blue', marker='o', s=20, label='z = x*y')
# Plot points for (x-1)*(y-1) with smaller marker size
ax.scatter(x2, y2, z2, c='red', marker='^', s=20, label='z = (x-1)*(y-1)')

# Add labels and title
ax.set_xlabel('X (Prime Numbers)')
ax.set_ylabel('Y (Prime Numbers)')
ax.set_zlabel('Z')
ax.set_title('3D Scatter Plot of Prime Number Products')

# Add legend
ax.legend()

# Disable auto-rotation to reduce rendering load
ax.view_init(elev=20, azim=45)

# Show plot
plt.show()
import numpy as np
import matplotlib.pyplot as plt

# Data
m = [-3,-2,-1,0,1,2,3]
k = [4.63,2.11,0.67,0.09,0.63,2.15,4.58]
n = len(m)

# Forming matrices for quadratic fitting
X = np.array([
    [x**2, x, 1] for x in m
])  # Matrix of terms [x^2, x, 1]
y = np.array(k)  # Vector of y values

# Solve for coefficients [a, b, c] using the normal equation
coefficients = np.linalg.lstsq(X, y, rcond=None)[0]
a, b, c = coefficients

print(f"Value of a: {a}")
print(f"Value of b: {b}")
print(f"Value of c: {c}")

# Generate parabola points
x_vals = np.linspace(min(m) - 1, max(m) + 1, 500)  # Smooth x values for the parabola
y_vals = a * x_vals**2 + b * x_vals + c  # Corresponding y values

# Plotting
plt.scatter(m, k, color='red', label='Data points')  # Original data points
plt.plot(x_vals, y_vals, color='blue', linestyle='-.', label='Best fit parabola')  # Parabola

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Quadratic Fit')
plt.legend()
plt.show()

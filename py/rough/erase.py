import numpy as np
import matplotlib.pyplot as plt

# Constants
G = 6.67430e-11  # Gravitational constant, m^3 kg^-1 s^-2
AU = 1.496e11    # Astronomical Unit in meters

# Semi-major axis (distance between star and planet), fixed at 1 AU
a = AU

# Range of masses
star_masses = np.linspace(0.5, 2.0, 5) * 1.989e30    # 0.5 to 2 Solar masses
planet_masses = np.linspace(0.1, 5.0, 5) * 5.972e24  # 0.1 to 5 Earth masses

# Create meshgrid for all combinations of star and planet masses
S, P = np.meshgrid(star_masses, planet_masses)

# Calculate orbital period using Kepler's Third Law
T = 2 * np.pi * np.sqrt(a**3 / (G * (S + P)))  # in seconds
T_days = T / (60 * 60 * 24)  # convert to days

# Plotting the result
plt.figure(figsize=(10, 6))
cp = plt.contourf(S / 1.989e30, P / 5.972e24, T_days, levels=20, cmap='viridis')
plt.colorbar(cp, label='Orbital Period (days)')
plt.xlabel('Star Mass (Solar Masses)')
plt.ylabel('Planet Mass (Earth Masses)')
plt.title("Kepler's 3rd Law: Orbital Period vs Star and Planet Mass")
plt.grid(True)
plt.tight_layout()
plt.show()
# Computational Physics _ B21+E14+E22
# GROUP : 21
# GROUP MEMBERS :
#               Aryan Kumar     24BAI10594
#               Piyush Gaur     24BAI10307
#               ADITYA AMAN     24BAI10129
#               APEKSHA SABOO   24BAI10636

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Ellipse, Circle
# from matplotlib.animation import FuncAnimation  # Removed animation import

# =============================================
# 1. Constants and Initial Conditions
# =============================================
G = 6.67430e-11  # Gravitational constant (m³/kg/s²)

M_star = 2.0e30       # Sun-like star
m_planet = 6.0e24     # Earth-like planet

a = 1.5e11
e = 0.5

T = 2 * np.pi * np.sqrt(a**3 / (G * (M_star + m_planet)))
b = a * np.sqrt(1 - e**2)

dt = T / 1000
t_max = 2 * T
steps = int(t_max / dt)

x, y = np.zeros(steps), np.zeros(steps)
vx, vy = np.zeros(steps), np.zeros(steps)

x[0] = a * (1 - e)
y[0] = 0
vx[0] = 0
vy[0] = np.sqrt(G * M_star * (1 + e) / (a * (1 - e)))

for i in range(steps - 1):
    r = np.sqrt(x[i]**2 + y[i]**2)
    ax = -G * M_star * x[i] / r**3
    ay = -G * M_star * y[i] / r**3
    
    vx[i+1] = vx[i] + ax * dt
    vy[i+1] = vy[i] + ay * dt
    
    x[i+1] = x[i] + vx[i+1] * dt
    y[i+1] = y[i] + vy[i+1] * dt

# =============================================
# 3. Visualization (Kepler's Laws and Mass Effects)
# =============================================
plt.figure(figsize=(18, 12))

# Kepler's 1st Law
plt.subplot(2, 2, 1)
plt.plot(x, y, 'b-', label="Planet's orbit")
plt.scatter([0], [0], color='yellow', s=200, label='Star')
plt.gca().add_patch(Ellipse((0, 0), 2*a, 2*b, angle=0, fill=False, linestyle='--', color='gray'))
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.title("Kepler's 1st Law: Elliptical Orbit")
plt.legend()
plt.grid()
plt.axis('equal')

# Kepler's 2nd Law
plt.subplot(2, 2, 2)
plt.plot(x, y, 'b-', alpha=0.5)
t_intervals = [0, 100, 200, 300]
colors = ['orange', 'green', 'red']
for i in range(len(t_intervals) - 1):
    start = t_intervals[i]
    end = t_intervals[i + 1]
    plt.fill_between(x[start:end], y[start:end], color=colors[i], alpha=0.3)
    plt.plot([0, x[start]], [0, y[start]], 'k-')
    plt.plot([0, x[end]], [0, y[end]], 'k-')

plt.scatter([0], [0], color='yellow', s=200, label='Star')
plt.title("Kepler's 2nd Law: Equal Areas in Equal Times")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.legend()
plt.grid()
plt.axis('equal')

# Kepler's 3rd Law
plt.subplot(2, 2, 3)
a_values = np.linspace(1e11, 3e11, 5)
T_values = []
for a_val in a_values:
    T_val = 2 * np.pi * np.sqrt(a_val**3 / (G * (M_star + m_planet)))
    T_values.append(T_val)

plt.plot(a_values**3, np.array(T_values)**2, 'bo-')
plt.xlabel("a³ (m³)")
plt.ylabel("T² (s²)")
plt.title("Kepler's 3rd Law: T² ∝ a³")
plt.grid()

# Mass Effects
plt.subplot(2, 2, 4)
M_star_values = np.linspace(1e30, 3e30, 5)
T_M = [2 * np.pi * np.sqrt(a**3 / (G * (M + m_planet))) for M in M_star_values]
plt.plot(M_star_values, T_M, 'ro-', label="Varying Star Mass")

m_planet_values = np.linspace(1e24, 1e26, 5)
T_m = [2 * np.pi * np.sqrt(a**3 / (G * (M_star + m))) for m in m_planet_values]
plt.plot(m_planet_values, T_m, 'go-', label="Varying Planet Mass")

plt.xlabel("Mass (kg)")
plt.ylabel("Orbital Period (s)")
plt.title("Effect of Mass on Orbital Period")
plt.legend()
plt.grid()

plt.tight_layout()
plt.suptitle("Combined Visualization of Kepler's 3 Laws with Mass Effects", fontsize=16, y=1.02)
plt.show()


# -------------------------------
# Additional Static Barycenter Plots
# -------------------------------
def simulate_orbit(m1, m2, r0, v0, dt, steps):
    r1 = np.array([-m2/(m1+m2)*r0, 0.0])
    r2 = np.array([ m1/(m1+m2)*r0, 0.0])
    v1 = np.array([0.0, -m2/(m1+m2)*v0])
    v2 = np.array([0.0,  m1/(m1+m2)*v0])
    
    traj1 = [r1.copy()]
    traj2 = [r2.copy()]
    
    r = r2 - r1
    dist = np.linalg.norm(r)
    F = G * m1 * m2 / dist**3 * r
    a1_prev =  F / m1
    a2_prev = -F / m2
    
    for _ in range(steps):
        r1 += v1 * dt + 0.5 * a1_prev * dt**2
        r2 += v2 * dt + 0.5 * a2_prev * dt**2
        
        r = r2 - r1
        dist = np.linalg.norm(r)
        F = G * m1 * m2 / dist**3 * r
        a1 =  F / m1
        a2 = -F / m2
        
        v1 += 0.5 * (a1_prev + a1) * dt
        v2 += 0.5 * (a2_prev + a2) * dt
        
        traj1.append(r1.copy())
        traj2.append(r2.copy())
        a1_prev, a2_prev = a1, a2
    
    return np.array(traj1), np.array(traj2)

def calculate_period(traj, dt):
    y = traj[:,1]
    zero_crossings = np.where(np.diff(np.sign(y)))[0]
    return (zero_crossings[1] - zero_crossings[0]) * dt if len(zero_crossings) > 1 else np.nan

def plot_orbits(mass_configs, r0, v0, dt, steps):
    fig, axes = plt.subplots(1, len(mass_configs), figsize=(15, 5))
    if len(mass_configs) == 1:
        axes = [axes]

    for ax, (m1, m2, label) in zip(axes, mass_configs):
        traj1, traj2 = simulate_orbit(m1, m2, r0, v0, dt, steps)
        ax.plot(traj1[:,0], traj1[:,1], 'r-', lw=1, label=f"Star ({m1/2e30:.1f} $M_\\odot$)")
        ax.plot(traj2[:,0], traj2[:,1], 'b-', lw=1, label=f"Planet ({m2/6e24:.1f} $M_\\oplus$)")
        ax.scatter(traj1[0,0], traj1[0,1], color='red', s=50)
        ax.scatter(traj2[0,0], traj2[0,1], color='blue', s=50)
        ax.scatter(0, 0, color='black', s=30, marker='+')
        
        T1 = calculate_period(traj1, dt)
        T2 = calculate_period(traj2, dt)
        
        info_text = (
            f"{label}\n"
            f"Mass ratio: {m1/m2:.1e}\n"
            f"Star period: {T1/86400:.1f} days\n"
            f"Planet period: {T2/86400:.1f} days"
        )
        ax.text(0.02, 0.98, info_text, transform=ax.transAxes,
                va='top', ha='left', fontsize=9,
                bbox=dict(facecolor='white', alpha=0.8, edgecolor='gray'))
        
        ax.set_aspect('equal')
        ax.set_xlabel("x (m)")
        ax.set_ylabel("y (m)")
        ax.legend(loc='lower right')

    plt.tight_layout()
    plt.show()

def simulate_orbit(m1, m2, r0, v0, dt, steps):
    """
    Simulate two-body motion in center-of-mass frame using forward Euler.
    Returns arrays of positions for body1 (star) and body2 (planet).
    """
    # Initial positions so that m1*r1 + m2*r2 = 0
    r1 = np.array([-m2/(m1+m2)*r0, 0.0])
    r2 = np.array([ m1/(m1+m2)*r0, 0.0])
    # Initial velocities so that m1*v1 + m2*v2 = 0
    v1 = np.array([0.0, -m2/(m1+m2)*v0])
    v2 = np.array([0.0,  m1/(m1+m2)*v0])

    traj1 = [r1.copy()]
    traj2 = [r2.copy()]

    for _ in range(steps):
        # vector from 1 to 2
        r = r2 - r1
        dist = np.linalg.norm(r)
        # gravitational force
        F = G * m1 * m2 / dist**3 * r
        # accelerations
        a1 =  F / m1
        a2 = -F / m2
        # update velocities
        v1 += a1 * dt
        v2 += a2 * dt
        # update positions
        r1 += v1 * dt
        r2 += v2 * dt
        # store
        traj1.append(r1.copy())
        traj2.append(r2.copy())

    return np.array(traj1), np.array(traj2)

if __name__ == "__main__":
    # Common simulation parameters
    r0    = 1.5e11   # initial separation in meters (~1 AU)
    v0    = 3.0e4    # initial speed in m/s (~Earth orbital speed)
    dt    = 1e4      # time step in seconds
    steps = 5000     # number of steps per run

    # Define mass configurations: (star_mass, planet_mass, label)
    mass_configs = [
        (2e30,      6e24,   "Earth–Sun"),       # Sun & Earth
        (2e30,      1.9e27, "Jupiter–Sun"),     # Sun & Jupiter
        (1e30,      1e30,   "Equal-Mass Stars") # Binary equal-mass
    ]

    # Set up plots
    fig, axes = plt.subplots(1, len(mass_configs), figsize=(5*len(mass_configs), 5))
    if len(mass_configs) == 1:
        axes = [axes]

    for ax, (m1, m2, label) in zip(axes, mass_configs):
        traj1, traj2 = simulate_orbit(m1, m2, r0, v0, dt, steps)
        # plot star and planet paths
        ax.plot(traj1[:,0], traj1[:,1], lw=1, label="Star")
        ax.plot(traj2[:,0], traj2[:,1], lw=1, label="Planet")
        ax.scatter(0, 0, color="red", s=30, label="Barycenter")
        ax.set_aspect('equal', 'box')
        ax.set_title(label)
        ax.set_xlabel("x (m)")
        ax.set_ylabel("y (m)")
        ax.legend()

    plt.tight_layout()
    plt.show()

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
import numpy as np
import matplotlib.pyplot as plt

# Gravitational constant
G = 6.67430e-11  # m^3 kg^-1 s^-2

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
    (2e30,      6e24,   "Earth–Sun"),        # Sun & Earth
    (2e30,      1.9e27, "Jupiter–Sun"),      # Sun & Jupiter
    (1e30,      1e30,   "Equal–Mass Stars")  # Binary equal-mass
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
        ax.scatter(0, 0, color="black", s=30, label="Barycenter")
        ax.set_aspect('equal', 'box')
        ax.set_title(label)
        ax.set_xlabel("x (m)")
        ax.set_ylabel("y (m)")
        ax.legend()

    plt.tight_layout()
    plt.show()

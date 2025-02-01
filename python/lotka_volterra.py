import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Define the Lotka-Volterra model parameters
a = 1.0  # Prey growth rate
b = 0.1  # Predation rate
c = 1.5  # Predator mortality rate
d = 0.075  # Predator growth rate due to hunting prey

# Define the system of differential equations
def lotka_volterra(t, z):
    x, y = z
    dxdt = a * x - b * x * y
    dydt = d * x * y - c * y
    return [dxdt, dydt]

# Initial conditions
x0 = 10  # Initial prey population
y0 = 5   # Initial predator population

# Time interval
t_span = (0, 200)
t_eval = np.linspace(t_span[0], t_span[1], 1000)

# Solve the system of differential equations
sol = solve_ivp(lotka_volterra, t_span, [x0, y0], t_eval=t_eval)

# Extract solutions
t = sol.t
x = sol.y[0]
y = sol.y[1]

# Plot population dynamics over time
plt.figure(figsize=(12, 5))
plt.plot(t, x, label="Prey (x)", color="blue")
plt.plot(t, y, label="Predators (y)", color="red")
plt.xlabel("Time")
plt.ylabel("Population")
plt.title("Predator-Prey Population Dynamics")
plt.legend()
plt.grid()
plt.show()

# Plot phase diagram
plt.figure(figsize=(6, 6))
plt.plot(x, y, color="purple")
plt.xlabel("Prey (x)")
plt.ylabel("Predators (y)")
plt.title("Phase Diagram of the Lotka-Volterra Model")
plt.grid()
plt.show()

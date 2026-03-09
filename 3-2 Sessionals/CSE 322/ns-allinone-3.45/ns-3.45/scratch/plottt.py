#!/usr/bin/env python3
"""
Plot throughput comparison between TCP Reno and TCP RenoJ
Run AFTER both simulations:
  ./ns3 run tcpreno
  ./ns3 run renoJtest
Then:
  python3 plot_throughput.py
"""

import matplotlib.pyplot as plt
import numpy as np

def read_throughput(filename):
    times = []
    throughputs = []
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            parts = line.split()
            if len(parts) >= 2:
                times.append(float(parts[0]))
                throughputs.append(float(parts[1]))
    return np.array(times), np.array(throughputs)

# Read data
t_reno,  tp_reno  = read_throughput("throughput-Reno.tr")
t_renoj, tp_renoj = read_throughput("throughput-RenoJ.tr")

# ---- Plot ----
fig, ax = plt.subplots(figsize=(10, 5))

ax.plot(t_reno,  tp_reno,  color='red',   linewidth=0.8, label='TCP Reno',  alpha=0.85)
ax.plot(t_renoj, tp_renoj, color='green', linewidth=0.8, label='TCP RenoJ', alpha=0.85)

ax.set_xlabel("time/s",        fontsize=12)
ax.set_ylabel("throughput/Kbps", fontsize=12)
ax.set_title("throughput",     fontsize=13)
ax.legend(fontsize=11)
ax.grid(True, linestyle='--', alpha=0.4)
ax.set_xlim(left=0)
ax.set_ylim(bottom=0)

plt.tight_layout()
plt.savefig("throughput_comparison.png", dpi=150)
print("Saved: throughput_comparison.png")

# ---- Print average throughputs ----
# Skip first 10s (warm-up)
mask_reno  = t_reno  > 10
mask_renoj = t_renoj > 10
avg_reno  = np.mean(tp_reno[mask_reno])   if mask_reno.any()  else 0
avg_renoj = np.mean(tp_renoj[mask_renoj]) if mask_renoj.any() else 0

print(f"\nAverage throughput (after 10s warm-up):")
print(f"  TCP Reno  : {avg_reno:.1f} Kbps")
print(f"  TCP RenoJ : {avg_renoj:.1f} Kbps")
print(f"  Improvement: {((avg_renoj - avg_reno) / avg_reno * 100):.1f}%")

plt.show()
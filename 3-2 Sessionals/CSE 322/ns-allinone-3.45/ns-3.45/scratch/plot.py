import matplotlib.pyplot as plt
import os

base = os.path.dirname(os.path.abspath(__file__))

def load_data(filename):
    time = []
    cwnd = []

    with open(filename) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 2:
                continue
            try:
                time.append(float(parts[0]))
                cwnd.append(float(parts[1]))
            except ValueError:
                continue   # header বা text line হলে skip করো

    return time, cwnd

# load files
t1, cwnd1 = load_data("/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/finalNewReno.txt")
t2, cwnd2 = load_data("/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/finalRenoJ.txt")

# plot
plt.figure(figsize=(8,5))
plt.plot(t1, cwnd1, label="TcpNewReno", linewidth=2)
plt.plot(t2, cwnd2, label="TcpRenoJ", linewidth=2)
plt.xlabel("Time (seconds)")
plt.ylabel("Congestion Window (bytes)")
plt.title("TCP Congestion Window Comparison")
plt.legend()
plt.grid(True)
plt.show()
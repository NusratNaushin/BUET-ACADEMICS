import matplotlib.pyplot as plt

time = []
cwnd = []

with open("cwnd.txt") as f:
    for line in f:
        parts = line.strip().split()
        if len(parts) == 2:   # শুধু time + cwnd লাইন নেবে
            t, c = parts
            time.append(float(t))
            cwnd.append(int(c))

plt.plot(time, cwnd)
plt.xlabel("Time (s)")
plt.ylabel("Congestion Window (bytes)")
plt.title("TCP RenoJ: Congestion Window vs Time")
plt.grid(True)
plt.show()

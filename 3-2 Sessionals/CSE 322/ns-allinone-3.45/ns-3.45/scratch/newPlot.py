import matplotlib.pyplot as plt

def read_file(filename):
    t = []
    th = []
    with open(filename) as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) == 2:
                time, throughput = parts
                t.append(float(time))
                th.append(float(throughput))
    return t, th

t1, th1 = read_file("newrenoThrpt.txt")
t2, th2 = read_file("renoJThrpt.txt")

plt.plot(t1, th1, label="TCP Reno")
plt.plot(t2, th2, label="TCP RenoJ")

plt.xlabel("Time (s)")
plt.ylabel("Throughput (Kbps)")
plt.title("Throughput vs Time")
plt.legend()
plt.grid(True)
plt.show()
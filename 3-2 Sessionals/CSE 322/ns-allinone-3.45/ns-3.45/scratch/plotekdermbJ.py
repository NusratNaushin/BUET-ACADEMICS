import matplotlib.pyplot as plt

def load_file(file):
    t=[]
    cwnd=[]
    
    with open(file) as f:
        for line in f:
            parts = line.split()

            if len(parts) != 2:
                continue

            t.append(float(parts[0]))
            cwnd.append(float(parts[1]) / 1024)

    return t,cwnd


t1,c1 = load_file("ekmbJ.txt")
t2,c2 = load_file("dermbJ.txt")

plt.plot(t1,c1,label="RenoJ 1Mb")
plt.plot(t2,c2,label="RenoJ 1.5Mb")

plt.xlabel("Time(s)")
plt.ylabel("CWND (packets)")
plt.legend()
plt.grid()

plt.show()
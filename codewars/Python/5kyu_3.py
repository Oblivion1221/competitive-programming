import math
def ex_euler(n):
    h = 1.0 / n
    xk = 0
    yk = 1
    sm = 0
    Y = [1.0]
    Z = [1.0]

    for i in range(n):
        
        yk += (2 - math.exp(-4 * xk) - 2 * yk) * h
        Y.append(yk)

        xk += h

        zk = 1 + 0.5 * math.exp(-4 * xk) - 0.5 * math.exp(-2 * xk)
        Z.append(zk)

        print(Y, Z)

    for i in range(len(Y)):
        sm += abs(Y[i] - Z[i]) / Z[i]

    return int(sm/(n+1)*1000000) / 1000000.0
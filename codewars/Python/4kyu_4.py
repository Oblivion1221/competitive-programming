def green(n):
    i = 0
    while n > 0:
        if (i * i) % (10 ** len(str(i))) == i and i:
            n -= 1
            print("n = " + str(n) + " i = " + str(i))
        i += 1
    return i - 1

print(green(100))
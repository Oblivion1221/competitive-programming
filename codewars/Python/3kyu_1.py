def fib(n):
    """Calculates the nth Fibonacci number"""
    def fib_iter(a, b, p, q, cnt):
        if cnt == 0:
            return b
        elif not (cnt % 2):
            return fib_iter(a, b, p ** 2 + q ** 2, q ** 2 + 2 * p * q, cnt // 2)
        else:
            return fib_iter(b * q + a * q + a * p, b * p + a * q, p, q, cnt - 1)

    return fib_iter(1, 0, 0, 1, n)

print(fib(100000))
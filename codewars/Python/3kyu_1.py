def fib(n):
    """Calculates the nth Fibonacci number"""
    def pfib_iter(a, b, p, q, cnt):
        if cnt == 0:
            return b
        elif not (cnt % 2):
            return pfib_iter(a, b, p ** 2 + q ** 2, q ** 2 + 2 * p * q, cnt // 2)
        else:
            return pfib_iter(b * q + a * q + a * p, b * p + a * q, p, q, cnt - 1)

    def nfib_iter(a, b, cnt):
        if cnt == 0:
            return a
        else:
            return nfib_iter(b - a, a, cnt + 1)

    if n >= 0:
        return pfib_iter(1, 0, 0, 1, n)
    else:
        return nfib_iter(0, 1, n)
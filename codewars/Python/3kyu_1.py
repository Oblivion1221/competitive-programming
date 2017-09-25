def fib(n):
    """Calculates the nth Fibonacci number"""
    def fib_iter(a, b, cnt):
        if cnt == 0:
            return b
        else:
            return fib_iter(a + b, a, cnt - 1)

    return fib_iter(1, 0, n)

print(fib(10))
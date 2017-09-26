def last_digit(lst):
    def fast-expt(b, n):
        if not n:
            return 1
        elif not (n % 2):
            return fast-expt(b, n / 2) * fast-expt(b, n / 2)
        else:
            return b * fast-expt(b, n - 1)

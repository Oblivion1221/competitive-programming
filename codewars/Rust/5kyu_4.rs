fn perimeter(n: u64) -> u64 {
    let mut res = 0;
    for i in 0..n + 1 {
        res += fib(i + 1);
    }
    res * 4
}

fn fib(n: u64) -> u64 {
    fn fib_iter(a: u64, b: u64, p: u64, q: u64, cnt: u64) -> u64 {
        if cnt == 0 {
            return b;
        } else if cnt % 2 == 0 {
            return fib_iter(a, b, p * p + q * q, q * q + 2 * p * q, cnt / 2);
        } else {
            return fib_iter(b * q + a * q + a * p, b * p + a * q, p, q, cnt - 1);
        }
    }
    return fib_iter(1, 0, 0, 1, n);
}

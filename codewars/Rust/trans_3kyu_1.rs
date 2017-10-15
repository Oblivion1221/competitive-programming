fn fib(n: i64) -> u64 {
    fn pfib_iter(a: u64, b: u64, p: u64, q: u64, cnt: i64) -> u64 {
        if cnt == 0 {
            return b;
        } else if cnt % 2 == 0 {
            return pfib_iter(a, b, p * p + q * q, q * q + 2 * p * q, cnt / 2);
        } else {
            return pfib_iter(b * q + a * q + a * p, b * p + a * q, p, q, cnt - 1);
        }
    }
    
    fn nfib_iter(a: u64, b: u64, cnt: i64) -> u64 {
        match cnt {
            0 => a,
            _ => nfib_iter(b - a, a, cnt + 1),
        }
    }

    match n >= 0 {
        true => pfib_iter(1, 0, 0, 1, n),
        false => nfib_iter(0, 1, n),
    }
}

fn main() {
    println!("{}", fib(6));
    println!("{}", fib(-6));
}
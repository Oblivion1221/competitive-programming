fn solequa(n: u64) -> Vec<(u64, u64)> {
    let mut res: Vec<(u64, u64)> = Vec::new();
    let mut i: u64 = 1;
    while i * i <= n {
        if n % i == 0 {
            // println!("{} {}", i, n / i);
            if (i + n/i) % 2 == 0 && (n/i - i) % 4 == 0 {
                res.push(((i + n/i) / 2, (n/i - i) / 4));
            }
        }
        i += 1;
    }
    res
}
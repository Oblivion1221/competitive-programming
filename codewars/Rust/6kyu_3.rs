// Wrong

fn prod2sum(a: i64, b: i64, c: i64, d: i64) -> Vec<(i64, i64)> {
    let mut res: Vec<(i64, i64)> = Vec::new();
    let tmp = (a*a+b*b) * (c*c+d*d);
    let mut n = 0;

    while n * n < tmp {
        n += 1;
    }

    for i in 0..n+1 {
        if ((tmp - i * i) as f64).sqrt() - ((tmp - i * i) as f64).sqrt().floor() < 1e-10 {
            if i <= ((tmp - i * i) as f64).sqrt() as i64 {
                res.push((i, ((tmp - i * i) as f64).sqrt() as i64));
            }
        }
    }
        
    res
}
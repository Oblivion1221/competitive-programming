fn len_curve(n: i32) -> f64 {
    let h: f64 = 1.0 / (n as f64);
    let mut tot = 0.0;
    for i in 0..n {
        let dy = fx(fx(h * ((i + 1) as f64)) - fx(h * (i as f64)));
        let dx = fx(h);
        tot += (dy + dx).sqrt();
    }
    
    tot
}

fn fx(x: f64) -> f64 {
    x * x
}
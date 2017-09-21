use std::f64::consts::PI;

fn simpson(n: i32) -> f64 {
    let h = (PI - 0.0) / (n as f64);
    let mut sum1 = 0.0;
    let mut sum2 = 0.0;
    for i in 1..n/2+1 {
        sum1 += fx(0.0 + (2 * i - 1) as f64 * h);
    }
    for i in 1..n/2 {
        sum2 += fx(0.0 + (2 * i) as f64 * h);
    }
    1.0 / 3.0 * h * (0.0 + fx(PI) + 4.0 * sum1 + 2.0 * sum2)
}

fn fx(x: f64) -> f64 {
    3.0 / 2.0 * x.sin() * x.sin() * x.sin()
}
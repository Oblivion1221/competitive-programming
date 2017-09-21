use std::f64::consts::PI;

fn rnd10(f: f64) -> f64 { (f * 1e10).round() / 1e10 }

fn iter_pi(epsilon: f64) -> (i32, f64) {
    let mut cnt: i32 = 0;
    let mut res: f64 = 0.0;
    loop {
        cnt += 1;
        res += (-1.0_f64).powf((cnt-1) as f64) * 1.0 / (2.0 * (cnt as f64) - 1.0);
        if (4.0 * res - PI).abs() < epsilon { break; }
    }

    (cnt, rnd10(4.0 * res))
}
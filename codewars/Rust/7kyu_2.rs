use std::f64::consts::PI;
fn square_area_to_circle(size:f64) -> f64 {
    (size.sqrt() / 2.0).powi(2) * PI
}

fn main() {
    println!("{}", square_area_to_circle(9.0));
}
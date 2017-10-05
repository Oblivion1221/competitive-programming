fn race(v1: i32, v2: i32, g: i32) -> Option<Vec<i32>> {
    // println!("v1 = {}, v2 = {}, g = {}", v1, v2, g);
    if v2 <= v1 {
        return None;
    } else {
        let t = g as f32 / (v2 - v1) as f32 * 3600.0;
        let h = (t / 3600.0) as i32 ;
        let mn = (t / 60.0) as i32 % 60;
        let s = t as i32 % 60;
        // println!("h = {}, mn = {}, s = {}", h, mn, s);
        return Some(vec![h, mn, s]);
    }
}

fn main() {
    println!("{:?}", race(720, 850, 70));
}
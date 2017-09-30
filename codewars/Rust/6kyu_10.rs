fn find_nb(m: u64) -> i32 {
    let mut a = 0;
    let mut i: u64 = 1;
    while a != m {
        if a > m {
            return -1;
        }
        a += i.pow(3u32);
        i += 1;
    }
    (i - 1) as i32
}

// 66666
// fn find_nb(n: u64) -> i32 {
//     let kk = (4.0 * n as f64).sqrt().sqrt().floor() as u64;
//     if 4u64 * n == kk * kk * (kk + 1u64) * (kk + 1u64)
//         {kk as i32}
//     else
//         {-1}
// }
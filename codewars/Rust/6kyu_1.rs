fn comp(a: Vec<i64>, b: Vec<i64>) -> bool {
    if a.len() != b.len() || a == [] || b == [] {
        return false
    }
    let mut a = a;
    let mut b = b;
//     let mut a_abs: Vec<i64> = Vec::new();
//     for i in a {
//         a_abs.push(i.abs());
//     }
    a.sort_by(|a, b| a.abs().cmp(&b.abs()));
    b.sort();
    for i in 0..a.len() {
        if a[i] * a[i] != b[i] {
            return false
        }
    }
    true
}
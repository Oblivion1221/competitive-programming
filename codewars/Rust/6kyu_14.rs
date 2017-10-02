fn game(n: u64) -> Vec<u64> {
    match n * n % 2 {
        0 => vec![n*n / 2],
        1 => vec![n*n, 2],
        _ => vec![],
    }
}
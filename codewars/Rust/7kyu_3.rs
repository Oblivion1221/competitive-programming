fn row_sum_odd_numbers(n:i64) -> i64 {
    let mut sum = 1;
    let mut i = 1;
    let mut res = 0;
    while i < n {
        sum += 2 * i;
        i += 1;
    }
    for j in 0..n {
        res += sum + 2 * j;
    }
    res
}
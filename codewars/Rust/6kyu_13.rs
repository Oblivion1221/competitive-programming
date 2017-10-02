fn divisors(integer: u32) -> Result<Vec<u32>, String> {
    let up = (integer as f64).sqrt().floor();
    let mut t: u32 = 2;
    let mut res: Vec<u32> = Vec::new();
    while t <= up as u32 {
        if integer % t == 0 {
            res.push(t);
            res.push(integer / t);
        }
        t += 1;
    }
    res.sort();
    if !res.is_empty() {
        return Ok(res);
    } else {
        return Err(format!("{} is prime", integer));
    }
}
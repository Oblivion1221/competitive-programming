fn count_sheep(sheep: &[bool]) -> u8 {
    let mut cnt: u8 = 0;
    for i in 0..sheep.len() {
        if sheep[i] == true {
            cnt += 1;
        }
    }
    
    cnt
}
fn fact(x: u64) -> u64 {
    let mut res = 1;
    for i in 1..x+1 {
        res *= i;
    }
    res
}

fn dec2_fact_string(nb: u64) -> String {
    let zeroz = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                       "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                            "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];
    let mut nb = nb;
    let mut res: Vec<String> = Vec::new();
    
    let mut i = 1;
    while nb != 0 {
        let tmp = nb % i;
        res.push(zeroz[tmp as usize].to_string());
        nb /= i;
        i += 1;
    }
    res.reverse();
    res.join("")
}

fn fact_string_2dec(s: String) -> u64 {
    // let mut tmp: u64 = s.parse().unwrap();
    // let mut res_vec: Vec<u64> = Vec::new();
    // let mut res = 0;
    // while tmp != 0 {
    //     res_vec.push(tmp % 10);
    //     tmp /= 10;
    // }
    // while res_vec.len() != 0 {
    //     let mut f = 1;
    //     // println!("res_vec = {:?}", res_vec);
    //     // println!("res_vec.len() = {}", res_vec.len());
    //     for i in 1..res_vec.len() {
    //         f *= i;
    //     }
    //     // println!("f = {}", f);
    //     res += res_vec.pop().unwrap() * (f as u64);
    //     // println!("res = {}", res);
    //     // println!();
    // }

    let mut res = 0;
    let mut f = s.len() - 1;
    let slen = s.len() - 1;
    let v: Vec<u8> = s.into_bytes();
    for i in 0..slen {
        if v[i] <= 57 {
            res += ((v[i] - 48) as u64) * fact(f as u64);
        } else {
            res += ((v[i] - 55) as u64) * fact(f as u64);
        }
        f -= 1;
    }

    res
}
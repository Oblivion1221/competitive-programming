fn xo(string: &'static str) -> bool {
    let mut x = 0;
    let mut o = 0;
    let bytes = string.as_bytes();
    for i in 0..bytes.len() {
        if bytes[i] == 111 || bytes[i] == 79 { 
            o += 1; 
        } else if bytes[i] == 120 || bytes[i] == 88 { 
            x += 1; 
        }
    }
    if x == o {
        true
    } else {
        false
    }
}

// fn xo(string: &'static str) -> bool {
//   string.chars().fold(0, |a, c|{
//     match c {
//       'x' | 'X' => a + 1,
//       'o' | 'O' => a - 1,
//       _ => a
//     }
//   }) == 0
// }
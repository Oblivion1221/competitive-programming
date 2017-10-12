fn brain_luck(code: &str, input: Vec<u8>) -> Vec<u8> {
    let mut i = 0u8;
    let mut res: Vec<u8> = Vec::new();
    let mut vptr: Vec<u8> = Vec::new();
    for c in code.chars() {
        match c {
            '>' => {
                i += 1u8;
                if i > input.len() {
                    vptr.push(0u8);
                }
            },
            '<' => i -= 1u8,
            '+' => vptr[i] += 1,
            '-' => vptr[i] -= 1,
            '.' => res.push(input[i]),
            ',' => vptr.push(input[i]),
            '[' => {
                if vptr[i] == 0 {
                    
                }
            },
            ']' =>,
        }
    }
    res
}
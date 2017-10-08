fn interpreter(tape: &str, data: &str) -> String {
    let mut data: Vec<&str> = data.split("").collect();
    let mut res = String::new();
    let mut cnt = 1;
    for c in tape.chars().cycle() {
        match c {
            '1' => {
                if data[cnt] == "1" {
                    data[cnt] = "0";
                } else if data[cnt] == "0" {
                    data[cnt] = "1";
                }
            },
            '0' => {
                if cnt < data.len() - 2 as usize {
                    cnt += 1;
                } else {
                    break;
                }
            },
            _ => (),
        }
    }
    for s in data {
        res.push_str(s);
    }
    res
}

fn main() {
    println!("{}", interpreter("10", "1010101"));
}
// my code below is shit

struct Cipher<'a> {
    map1: Vec<&'a str>,
    map2: Vec<&'a str>,
}

impl<'a> Cipher<'a> {
    fn new(map1: &'a str, map2: &'a str) -> Cipher<'a> {
        Cipher {
            map1: map1.split("").collect(),
            map2: map2.split("").collect(),
        }
    }

    fn encode(&self, string: &str) -> String {
        let s_vec: Vec<&str> = string.split("").collect();
        let mut res = String::new();
        for s in s_vec {
            if s != "" && self.map2.iter().any(|v| v == &s){
                res.push_str(self.map2[self.map1.iter().position(|&r| r == s).unwrap()]);
            } else {
                res.push_str(s);
            }
        }
        res
    }

    fn decode(&self, string: &str) -> String {
        let s_vec: Vec<&str> = string.split("").collect();
        let mut res = String::new();
        for s in s_vec {
            if s != "" && self.map1.iter().any(|v| v == &s){
                res.push_str(self.map1[self.map2.iter().position(|&r| r == s).unwrap()]);
            } else {
                res.push_str(s);
            }
        }
        res
    }
}

fn main() {
    let map1 = "abcdefghijklmnopqrstuvwxyz";
    let map2 = "etaoinshrdlucmfwypvbgkjqxz";

    let cipher = Cipher::new(map1, map2);

    let res1 = cipher.encode("xyz");
    let res2 = cipher.encode("abc");
    let res3 = cipher.encode("aeiou");
    let res4 = cipher.decode("eta");
    let res5 = cipher.decode("qxz");
    let res6 = cipher.decode("eirfg");
    let res7 = cipher.encode("xy___z");
    let res8 = cipher.decode("et___a");


    println!("{}", res1);
    println!("{}", res2);
    println!("{}", res3);
    println!("{}", res4);
    println!("{}", res5);
    println!("{}", res6);
    println!("{}", res7);
    println!("{}", res8);
}
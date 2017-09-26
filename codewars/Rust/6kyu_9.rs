fn my_first_interpreter(code: &str) -> String {
    // println!("input = {}", code);
    let code: Vec<&str> = code.split("").collect();

    let mut rec = 0;

    let mut res = String::new();

    for i in 0..code.len() {

        if code[i] == "+" {
            rec += 1;
        } else if code[i] == "." {
            res.push_str(String::from_utf16(&[rec as u16]).unwrap().as_str());
            // println!("res = {}", res);
        }
        
        if rec >= 255 {
            rec = -1;
        }
    }

    res.replace("\u{ffff}", "ÿ")
}

// The difference: "\u{ffff}" and "ÿ"
// \u{1d}!4JTV[\u{89}\u{8d}\u{99}\u{9c}\u{a0}¢¿ÕÖ×ààçèëóøú\u{0}\u{4}\u{6}\u{b}\u{12}$447RV[]cegjmns\u{8b}\u{8d}\u{97}\u{97}\u{9c}¦¦µ·ºÑÚÜìûü\u{2}\u{5}\n),7DDEIJYeey\u{85}\u{8a}\u{8c}\u{8c}\u{92}\u{94}\u{9a}½¾ËÐØÛãùú\u{ffff}\u{e}!
// \u{1d}!4JTV[\u{89}\u{8d}\u{99}\u{9c}\u{a0}¢¿ÕÖ×ààçèëóøú\u{0}\u{4}\u{6}\u{b}\u{12}$447RV[]cegjmns\u{8b}\u{8d}\u{97}\u{97}\u{9c}¦¦µ·ºÑÚÜìûü\u{2}\u{5}\n),7DDEIJYeey\u{85}\u{8a}\u{8c}\u{8c}\u{92}\u{94}\u{9a}½¾ËÐØÛãùúÿ\u{e}!

// \r\u{16}\u{1a}*1:;T\\_u\u{81}\u{94}\u{99}\u{99}\u{99}\u{9a}¤º»Ùßáå\u{4}\u{7}\t\u{1b}*+KLSbpwy|\u{87}\u{95}§³¼ÊØìí\u{ffff}\u{ffff}\u{16}\u{17}\u{17}$'**+5BENNOTX[\\aabefz|\u{7f}\u{81}\u{82}\u{85}\u{8f}\u{8f}\u{90}¡¦·½ÅÌ\r\u{10}\u{17}\u{1a} \"++/GT
// \r\u{16}\u{1a}*1:;T\\_u\u{81}\u{94}\u{99}\u{99}\u{99}\u{9a}¤º»Ùßáå\u{4}\u{7}\t\u{1b}*+KLSbpwy|\u{87}\u{95}§³¼ÊØìíÿÿ\u{16}\u{17}\u{17}$'**+5BENNOTX[\\aabefz|\u{7f}\u{81}\u{82}\u{85}\u{8f}\u{8f}\u{90}¡¦·½ÅÌ\r\u{10}\u{17}\u{1a} \"++/GT

// 我为什么就找不到 wrapping_add() 这种方法...
// fn my_first_interpreter(code: &str) -> String {
//     let mut out = String::new();
//     let mut mem = 0u8;
  
//     for c in code.chars() {
//         match c {
//             '+' => mem = mem.wrapping_add(1),
//             '.' => out.push(mem as char),
//             _ => (),
//         }
//     }
  
//     out
// }
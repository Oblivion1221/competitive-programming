use std::collections::VecDeque;
use std::cmp;

fn dbl_linear(n: u32) -> u32 {
    let mut u1: VecDeque<u32> = VecDeque::new();
    let mut u2: VecDeque<u32> = VecDeque::new();
    let mut cnt = 0;
    let mut m = 1;
    let mut bm = 1;
    loop {
        if cnt >= n { return m; }
        u1.push_back(2 * m + 1);
        u2.push_back(3 * m + 1);
        m = cmp::min(u1[0], u2[0]);

        if bm != m {
            cnt += 1;
        }
        
        if m == u1[0] {
            u1.pop_front();
        } else if m == u2[0] {
            u2.pop_front();
        }

        bm = m;
    }
}



// So slow:
//
// fn dbl_linear(n: u32) -> u32 {
//     let mut res = 1;
//     let mut num = 0;
//     let mut u: Vec<f32> = vec![0.0, 1.0];
//     while n >= num {
//         // println!("{} {}", res, num);
//         if (res - 1) % 2 == 0 || (res - 1) % 3 == 0 {
//             if u.contains(&((res - 1) as f32 / 2.0)) || u.contains(&((res - 1) as f32 / 3.0)) {
//                 // println!("(res - 1) / 2 = {:?}\n(res - 1) / 3 = {:?}", (res - 1) / 2, (res - 1) / 3);
//                 u.push(res as f32);
//                 num += 1;
//                 // println!("{:?}", u);
//             }                     
//         }
//         res += 1;
//     }

//     res - 1
// }

fn main() {
    println!("{}", dbl_linear(10));
    println!("{}", dbl_linear(20));
    println!("{}", dbl_linear(30));
    println!("{}", dbl_linear(50));
    println!("{}", dbl_linear(100));
}
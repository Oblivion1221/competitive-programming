fn trotter(n: i32) -> i32 {
    let mut res: Vec<i32> = Vec::new();
    let fck: Vec<i32> = vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
//     let mut sleep: bool = false;
    let mut i: i32 = 0;

    while res != fck {
        i += 1;
        let mut shit = i * n;
        while shit != 0 {
            if res.is_empty() {
                res.push(shit % 10);
            } else {
                  for r in &mut res {
                      if &mut (shit % 10) != r {
                          res.push(shit % 10);
                      }
                  }
            }
                
            shit /= 10;
        }
        res.sort();
    }

    i * n
}
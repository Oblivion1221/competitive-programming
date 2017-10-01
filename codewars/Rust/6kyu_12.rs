// Wait..

fn sjf(jobs: &[usize], index: usize) -> usize {
    let tar = jobs[index];
    // println!("{:#?}", tar);
    let mut jobs: Vec<usize> = jobs.to_vec();
    let mut res: usize = 0;
    jobs.sort();
    println!("{:?}", jobs);
    for j in jobs {
        match j != tar {
            true => res += j,
            false => { res += j; break; },
        }
    }
    res
}

fn main() {
    println!("{}", sjf(&[100], 0));
    println!("{}", sjf(&[3,10,20,1,2], 0));
    println!("{}", sjf(&[3, 10, 20, 1, 2, 3], 5));
}
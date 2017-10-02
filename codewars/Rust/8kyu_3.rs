fn last<T: Clone>(slice: &[T]) -> T {
    slice[slice.len()-1].clone()
}

// ojbk
// fn last<T: Clone>(slice: &[T]) -> T {
//   let l = slice.last();
//   match l {
//     None => panic!("empty"),
//     Some(x) => x.clone(),
//   }
// }
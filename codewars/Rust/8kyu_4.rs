fn repeat_str(src: &str, count: usize) -> String {
  let mut res = String::new();
  for _ in 0..count {
      res.push_str(src);
  }
  res
}
fn greet(input : &str) -> String {
  
  if input == "Johnny" {
    return "Hello, my love!".to_string();
  }
  
  return format!("Hello, {}!", input);
}
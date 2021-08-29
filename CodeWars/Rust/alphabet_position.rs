fn alphabet_position(text: &str) -> String {
    let arr: &[u8] = text;
    String::from(arr.join(' '));
}
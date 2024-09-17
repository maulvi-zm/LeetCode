impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut ans: i32 = 0;

        let mut pos = s.len() - 1;

        while (pos >= 0 && s.chars().nth(pos) == Some(' ')) {
            pos -= 1;
        }

        while (pos >= 0 && s.chars().nth(pos) != Some(' ')) {
            ans += 1;

            if pos == 0 {
                break;
            }
            
            pos -= 1;
        }

        ans
    }
}
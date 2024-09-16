impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut carry = 0;

        let minLength = std::cmp::min(a.len(), b.len());
        let maxLength = std::cmp::max(a.len(), b.len());
        
        let long;
        let short;

        if (minLength == b.len()){
            long = a;
            short = b;
        } else {
            long = b;
            short = a;
        }

        let mut ans = String::new();
        for i in (0..minLength) {
            if short.chars().nth(minLength-i-1) == Some('1') && long.chars().nth(maxLength-i-1) == Some('1') {
                if carry == 1 {ans.insert(0, '1')}
                else {ans.insert(0,'0')};

                carry = 1;
            } else if short.chars().nth(minLength-i-1) == Some('1') || long.chars().nth(maxLength-i-1) == Some('1') {
                if carry == 1 {ans.insert(0, '0'); carry = 1}
                else {ans.insert(0,'1')};
            } else {
                if carry == 1 {ans.insert(0, '1'); carry = 0}
                else {ans.insert(0,'0')};
            }
        }

        for i in (0..maxLength-minLength).rev() {
            if long.chars().nth(i) == Some('1') {
                if carry == 1 {ans.insert(0, '0'); carry = 1}
                else {ans.insert(0,'1')};
            } else {
                if carry == 1 {ans.insert(0, '1'); carry = 0}
                else {ans.insert(0,'0')};
            }
        }

        if carry == 1{
            ans.insert(0, '1');
        }

        ans
    }
}
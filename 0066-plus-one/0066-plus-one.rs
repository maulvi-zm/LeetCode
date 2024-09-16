impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut new_vec = digits.clone();

        let len = new_vec.len();

        new_vec[len - 1] += 1;

        if new_vec[len - 1] < 10 {return new_vec};

        new_vec[len - 1] -= 10;
        let mut container = 1;
        for i in (0..len-1).rev() {
            new_vec[i] = new_vec[i] + container; 
            
            container = 0;
            if new_vec[i] >= 10 {
                new_vec[i] -= 10;
                container = 1;
            }
        }

        if container != 0 {
            new_vec.insert(0, container);
        }

        return new_vec;
    }
}
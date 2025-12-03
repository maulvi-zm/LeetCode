class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        priority_queue<int> remainder_one;
        priority_queue<int> remainder_two;

        int sum = 0;
        for (auto num : nums) {
            sum += num;

            if (num % 3 == 1) {
                remainder_one.push(num);
                if (remainder_one.size() > 2) {
                    remainder_one.pop();
                }
            } else if (num % 3 == 2) {
                remainder_two.push(num);
                if (remainder_two.size() > 2) {
                    remainder_two.pop();
                }
            }
        }

        if (sum % 3 == 0) {
            return sum;
        } else if (sum % 3 == 1) {
            int min1;
            while (!remainder_one.empty()) {
                min1 = remainder_one.top();
                remainder_one.pop();
            }

            if (remainder_two.size() >= 2) {
                int num1 = remainder_two.top();
                remainder_two.pop();
                int num2 = remainder_two.top();

                if (num1 + num2 < min1) {
                    return sum - num1 - num2;
                } else {
                    return sum - min1;
                }
            } else {
                return sum - min1;
            }
        } else {
            int min2;
            while (!remainder_two.empty()) {
                min2 = remainder_two.top();
                remainder_two.pop();
            }
            
            if (remainder_one.size() >= 2) {
                int num1 = remainder_one.top();
                remainder_one.pop();
                int num2 = remainder_one.top();

                if (num1 + num2 < min2) {
                    return sum - num1 - num2;
                } else {
                    return sum - min2;
                }
            } else {
                return sum - min2;
            }
        }
    }
};
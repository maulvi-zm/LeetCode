class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);
        
        int m = A.size(), n = B.size();
        int leftCount = (m + n + 1) / 2;

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;         // partition A
            int j = leftCount - i;            // partition B

            int A_left  = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];

            int B_left  = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];

            // correct partition
            if (A_left <= B_right && B_left <= A_right) {
                if ((m + n) % 2 == 1) {
                    return max(A_left, B_left);
                }
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
            }
            // A_left too big â move left
            else if (A_left > B_right) {
                high = i - 1;
            }
            // A_left too small â move right
            else {
                low = i + 1;
            }
        }
        return 0.0; // never reached
    }
};
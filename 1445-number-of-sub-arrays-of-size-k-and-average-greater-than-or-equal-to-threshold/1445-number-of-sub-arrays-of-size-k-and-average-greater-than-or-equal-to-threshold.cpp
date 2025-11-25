class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int curr_sum = 0, ans = 0;

        for (int i = 0; i < n; i++){
            if (i >= k ){
                curr_sum -= arr[i-k];
            } 

            curr_sum += arr[i];

            if (i >= k - 1 && curr_sum / k >= threshold){
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<char> turbulence(n - 1);

        for (int i = 1; i < n; ++i){
            if (arr[i] > arr[i - 1]){
                turbulence[i-1]  = '>';
            } else if (arr[i] < arr[i - 1]){
                turbulence[i-1]  = '<';
            }  else {
                turbulence[i-1]  = '=';
            }
        }

        int localMax = 0, globalMax = 0;
        for (int i = 0; i < n - 1; ++i){
            if (turbulence[i] != '=' && i != 0 && turbulence[i] != turbulence[i-1]){
                localMax += 1;
            } else if (turbulence[i] == '='){
                localMax = 0;
            } else {
                localMax = 1;
            }

            globalMax = max(localMax, globalMax);
        }

        return globalMax + 1;
    }
};
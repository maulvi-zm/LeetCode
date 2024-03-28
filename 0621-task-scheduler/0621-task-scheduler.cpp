class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Container for all char
        int frequence[26] = {0};

        for (char task: tasks){
            frequence[task - 'A']++;
        }

        // Sorting
        sort(begin(frequence), end(frequence));

        int idle = (frequence[25] - 1) * (n + 1);

        // Reduce frequence from idle
        for(int i = 25; i >= 0; i--){
            frequence[i] == frequence[25] ? idle -= (frequence[i]-1) : idle -= frequence[i];
            
        }

        return idle > 0 ? tasks.size() + idle : tasks.size();
    }
};
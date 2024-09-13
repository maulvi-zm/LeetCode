class Solution {
private:
    vector<string> ans;
public:
    void makeParentheses(int buka, int tutup, string curr){
        if (buka == 0 && tutup == 0) ans.push_back(curr);

        if (buka > 0){
            makeParentheses(buka - 1, tutup, curr + "(");
        }

        if (tutup > 0 && curr != "" && buka < tutup){
            makeParentheses(buka, tutup - 1, curr + ")");
        }

    }

    vector<string> generateParenthesis(int n) {
        makeParentheses(n, n, "");

        return ans;    
    }
};
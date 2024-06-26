class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
    void dfs(int n, int lc, int rc, string ans) {
        if(ans.length() == n * 2) {
            res.push_back(ans);
            return;
        }
        if(lc < n) dfs(n, lc + 1, rc, ans+'(');
        if(lc > rc && rc < n) dfs(n, lc, rc + 1, ans+')');
        return;
    }

};

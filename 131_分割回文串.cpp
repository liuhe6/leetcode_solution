class Solution {
public:
    vector<vector<bool>> f;
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        f = vector<vector<bool>>(n, vector<bool>(n));
      // f状态为s的第i到第j的子串是否为回文串
      // 由于状态转移, 是j - 1, 所以j应该先循环j;
        for(int j = 0; j < s.size(); j ++) {
            for(int i = 0; i < s.size(); i++) {
                if(i == j) f[i][j] = true;
                else if(s[i] == s[j]) {
                  // i+1>j-1时, 说明只有两个字符
                    if(i + 1 > j - 1 || f[i + 1][j - 1]) f[i][j] = true;
                }
            }
        }
        dfs(s, 0);
        return res;
    }
    void dfs(string s, int u) {
        if(u == s.size()) res.push_back(path);
        else {
            for(int i = u; i < s.size(); i++) {
                if(f[u][i]) {
                    path.push_back(s.substr(u, i - u + 1));
                    dfs(s, i + 1);
                    path.pop_back();
                }
            }
        }
    }
};

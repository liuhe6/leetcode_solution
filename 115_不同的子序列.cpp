class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = ' ' + s, t = ' ' + t;
      // 状态是s的前i个字符串包含多少个t前j个字符串的 相同的子序列
        vector<vector<unsigned long long>> f(n + 1, vector<unsigned long long>(m + 1));
      // 如果t为空, 则不从s中选取, 也可以是一种方案;
        for(int i = 0; i <= n; i++) f[i][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
              // 如果不选取s[i], 则数量等同于f[i - 1][j]
                f[i][j] += f[i - 1][j];
               // 当s[i] 和 t[j]相等的时候,选取s[i], 则数量等同于f[i - 1][j - 1]
              // 最后和INT_MAX取余,完全是因为题目结果超出int了
                if(s[i] == t[j]) f[i][j] = (f[i - 1][j - 1] + f[i][j]) % INT_MAX;
                
            }
        }
        return f[n][m];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;

        s1 = ' ' + s1, s2 = ' ' + s2, s3= ' ' + s3;
        // 状态为s1的前i个字符和s2的前j个字符,是否能构成s3的前i+j个;
        // 这里理解一下, s3的前i+j一定由 s1的前i个和s2的前j个组成;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                // 两个空串可以组成空串
                if(!i && !j) f[i][j] = true;
                else{
                    // 分别判断最后一个字母由哪个字符串提供
                    if(i && s1[i] == s3[i + j]) f[i][j] = f[i - 1][j];
                    if(j && s2[j] == s3[i + j]) f[i][j] = f[i][j - 1] || f[i][j];
                }
            }
        }
        return f[n][m];
    }
};

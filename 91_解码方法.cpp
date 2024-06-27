class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        // f[i] 是到第i字符时, 解码的方案数
        vector<int> f(n + 1);
        f[0] = 1;
        // 和跳台阶类似,每个f[i] 由 f[i - 1]和f[i - 2] 转移而来,但是转移的过程需要满足条件
        for(int i = 1; i <= n; i++) {
            if(s[i] > '0' && s[i] <='9') f[i] += f[i - 1];
            if(i > 1) {
                int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if(t >= 10 && t <= 26) {
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
};

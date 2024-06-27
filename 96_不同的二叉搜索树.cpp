class Solution {
public:
    int numTrees(int n) {
        // 长度一样的时候,能够返回的搜索树种数 也一样, 比如1 - 5 和 6 - 10 的种数一样;
        // 状态数组设置成n + 1 这样才能计算f(n)
        vector<int> f(n + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                // 左边的和右边的是相乘的关系
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];        
    }
};

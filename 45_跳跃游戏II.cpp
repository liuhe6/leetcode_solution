class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        // 状态f是跳跃到i点所需要的最短步数
        // 数组nums可以分成好多段， 每一段都有相同的需求步数，所以f是非单调的递增数列
        for(int i = 1, j = 0; i < n; i++) {
            // j是能跳到i，最近的一个
            while(j + nums[j] < i) j++;
            // 跳到i的步数就是 跳到j的步数+1
            f[i] = f[j] + 1;
        }
        return f[n - 1];
    }
};

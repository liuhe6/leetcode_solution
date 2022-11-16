class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int f = nums[0], g = nums[0];
        // f存的是以i为右端点的情况下,最大的乘积，g则存的是最小乘积(考虑正负)
        // 所以f和g分别存在的3种情况就是nums[i]本身、i-1位的最大值和nums[i]的乘积、i-1位最小值和nums[i]的乘积(有可能nums[i]是负数)
        for(int i = 1; i < nums.size(); i++) {
            int a = nums[i], fa = f * a, ga = g * a;
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));
            res = max(res, f);
        }
        return res;
    }
};

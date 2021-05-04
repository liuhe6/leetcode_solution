class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if(j > k + 1 && nums[j] == nums[j - 1]) continue;
                while(j < k - 1 && nums[i] + nums[j] + nums[k - 1] <= 0) k--;
                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nusm[j], nums[k]});
                }
            }
        }
        return res;
    }
};
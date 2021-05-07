class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;    
    }

    void dfs(vector<int>& nums, int u)
    {
        if (u >= nums.size())
        {
            res.push_back(path);
            return;
        }

        dfs(nums, u + 1); //不选当前数，递归下一层
        path.push_back(nums[u]);  //选当前数
        dfs(nums, u + 1); //递归下一层
        path.pop_back(); //回溯
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }
    void dfs(vector<int>& candidates, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        } 
        for (int i = u; i < candidates.size(); i++) {
            if(candidates[i] > target) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i , target - candidates[i]);
            path.pop_back();
        }
    }
};  

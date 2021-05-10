class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* u) {
        if(!u) return 0;
        int left = max(0, dfs(u->left)), right = max(0, dfs(u->right));
        ans = max(ans, u->val + left + right);
        return u->val + max(left, right);
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
      //初始化为INT_MAX
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++) {
            for(int j =0; j < n; j++) {
              // 出发点初始化
                if(!i && !j) f[i][j] = grid[i][j];
                else {
                  // 这种判断方法，优雅地解决了边界的判断问题；
                    if(i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if(j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }
        return f[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        if(!m ) return 0;
        int n = o[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
              //不用管障碍物
                if(!o[i][j]) {
                  // 起点初始化
                    if(!i && !j) f[i][j] = 1;
                    else{
                      // i != 0可以从上一行转移
                        if(i) f[i][j] += f[i - 1][j];
                      // j != 0可以从上一列转移
                        if(j) f[i][j] += f[i][j - 1];
                    } 
                }
            }
        }
        return f[m - 1][n - 1];
    }
};

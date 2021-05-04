class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(!n) return res;
        int m = matrix[0].size();

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        vector<vector<bool>> st(n, vector<bool>(m));

        for(int i = 0, x = 0, y = 0, d = 1; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
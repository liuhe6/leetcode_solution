class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先用根据对角线翻转
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < i; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再水平翻转
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0, k = matrix[0].size() - 1; j < k; j++, k--) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};

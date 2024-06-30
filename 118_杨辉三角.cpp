class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> line(i + 1);
            line[0] = 1;
            line[i] = 1;
            for(int j = 1; j < i; j++) {
                line[j] = res[i - 1][j - 1] + res[i - 1][j]; 
            }
            res.push_back(line);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int k = 0;
        vector<vector<int>> res;
        while(k < a.size() && a[k][1] < b[0]) res.push_back(a[k++]);
        if(k < a.size()) {
            b[0] = min(b[0], a[k][0]);
            while(k < a.size() && a[k][0] <= b[1]) b[1] = max(b[1], a[k++][1]);
        }
        res.push_back(b);
        while(k < a.size()) res.push_back(a[k++]);
        return res;
    }
};

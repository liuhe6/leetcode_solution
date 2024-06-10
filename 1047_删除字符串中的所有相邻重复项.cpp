class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(auto c: s) {
            if(res.size() && res.back() == c ) res.pop_back();
            else res += c;
        }
        return res;
    }
};

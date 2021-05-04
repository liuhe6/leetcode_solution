class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs[0].size(); i++) {
            char t = strs[0][i];
            bool s = true;
            for(int j = 1; j < strs.size(); j++) {
                if(t == strs[j][i]) continue;
                else{
                    s = false;
                    break;
                } 
            }
            if(s) res += t;
            else return res;
        }
        return res;
    }
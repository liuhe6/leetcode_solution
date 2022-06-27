class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        for(int i = 0, j = 0; i < s.length(); i++) {
            m[s[i]]++;
            while(m[s[i]] > 1) m[s[j++]] --;
            res = max(res, i - j + 1);
        } 
        return res;
    }
};

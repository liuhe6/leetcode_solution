class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); //构建为set，方便查找

        vector<bool> dp(s.size()+1, false); //dp表示字符之间的隔板，n个字符有n+1个隔板
        dp[0] = true; //dp[0]是s[0]前面的隔板

        for(int i=1; i<=s.size(); ++i){
            for(int j=i; j>=0; --j){
                if(dict.find(s.substr(j,i-j))!=dict.end() && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

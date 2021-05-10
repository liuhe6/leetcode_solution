string solve(string str1,string str2){
    int len1=str1.size();
    int len2=str2.size();
    int maxlen=0;
    int last=0;
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxlen){
                    maxlen=dp[i][j];
                    last=i-1;
                }
            }else{
                dp[i][j]=0;
            }
        }
    }
    if(maxlen>0){
        return str1.substr(last-maxlen+1,maxlen);
    }else{
        return "-1";
    }
}
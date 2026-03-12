class Solution {
public:
    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]= f(i-1,j-1,word1,word2,dp);
        }else{
            return dp[i][j]= min(1 + f(i,j-1,word1,word2,dp),min(1 + f(i-1,j,word1,word2,dp),  1 + f(i-1,j-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        vector<double> prev(m+1,0);
        // for(int i=1;i<=n;i++){
        //     dp[i][0] = i;
        // }
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }

        for(int i=1;i<=n;i++){
            vector<double> curr(m+1,0);
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = min(1 + prev[j], min(1+prev[j-1], 1+ curr[j-1]));
                }
            }
            prev= curr;
        }
        return (int)prev[m];
        // return f(n-1, m-1, word1,word2,dp);

    }
};
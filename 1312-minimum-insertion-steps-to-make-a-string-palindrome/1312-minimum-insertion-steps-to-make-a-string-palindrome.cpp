class Solution {
public:
    int f(int left, int right, string &s, vector<vector<int>> & dp){
        if(left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        if(s[left]==s[right]){
            return dp[left][right] = 0 + f(left+1,right-1, s,dp);
        } else{
            return dp[left][right] =  1+ min(f(left+1, right,s,dp) , f(left, right-1,s,dp));
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
        // return f(left, right, s, dp);
    }
};
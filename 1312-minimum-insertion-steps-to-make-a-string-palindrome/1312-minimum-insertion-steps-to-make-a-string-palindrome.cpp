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
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(left, right, s, dp);
    }
};
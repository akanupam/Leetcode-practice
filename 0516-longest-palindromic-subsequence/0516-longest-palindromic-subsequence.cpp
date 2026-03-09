class Solution {
public:
    int f(int left, int right, string& s, vector<vector<int>>& dp){
        if(left==right) return 1;
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        if(s[left]==s[right]){
            return dp[left][right] =  2 + f(left+1,right-1, s,dp);
        }
        return dp[left][right] = 0 + max(f(left+1,right, s,dp), f(left, right-1, s,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        // vector<vector<int>> dp(n, vector<int>(n,0));
        vector<int> dp(n,0);
        // for(int i=0;i<n;i++){
        //     dp[i][i] = 1;
        // }
        for(int i=n-1;i>=0;i--){
            int prev = 0;
            dp[i] = 1;
            for(int j=i+1;j<n;j++){
                int temp = dp[j];
                if(s[i]==s[j]){
                    dp[j] = 2 + prev;
                }else{
                    dp[j] = max(dp[j],dp[j-1]);
                }
            prev = temp;
            }
        }
        // return f(left, right, s, dp);
        return dp[n-1];
    }
};
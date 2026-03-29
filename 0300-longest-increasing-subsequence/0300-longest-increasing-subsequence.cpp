class Solution {
public:
    int f(int ind, int prev_ind, vector<int> &nums, int n, vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len = f(ind + 1, prev_ind, nums, n,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len = max(len, 1+f(ind+1,ind,nums,n,dp));
        }
        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // return f(0, -1, nums, n,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int len = dp[i+1][j+1];
                if(j==-1||nums[i]>nums[j]){
                    len = max(len, 1+dp[i+1][i+1]);
                }
                dp[i][j+1] = len;
            }
        }
        return dp[0][0];
    }
};
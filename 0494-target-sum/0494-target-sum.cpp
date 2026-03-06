class Solution {
public:
    int f(vector<int>& nums, int k, int i, vector<vector<int>>& dp){
        if(i==0){
            if(k==0 && nums[0]==0) return 2;
            else if(k==0 || nums[0]==k) return 1;
            else return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int np = f(nums, k, i-1, dp);
        int p = 0;
        if(nums[i]<=k){
            p = f(nums, k-nums[i], i-1, dp);
        }
        return dp[i][k] = np + p;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n ;i++) totSum += nums[i];
        if(totSum<abs(target)) return 0;
        if((totSum+target)%2!=0) return 0;
        int k = (totSum+target)/2; 
        vector<int> dp(k+1,0);
        if(nums[0]==0){
            dp[0] = 2;
        }
        else {
            dp[0] = 1;
            if(nums[0]<=k) dp[nums[0]] = 1;
        }
        for(int i=1;i<n;i++){
            vector<int> curr(k+1, 0);
            for(int j=0;j<=k;j++){
                int np = dp[j];
                int p = 0;
                if(nums[i]<=j){
                    p = dp[j- nums[i]];
                }
                curr[j] = p+np;
            }
            dp = curr;
        }
        int ans = dp[k];
        return ans;
    }
};
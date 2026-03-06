class Solution {
public:
    int f(vector<int>& nums, vector<vector<int>>& dp,int k, int i){
        // if(k==0) return 1;
        if(i==0){
            return (k%nums[0]==0);
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int np = f(nums, dp, k, i-1);
        int p = 0;
        if(nums[i]<=k){
            p = f(nums, dp, k-nums[i], i);
        }
        return dp[i][k] = np+p;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(coins, dp, amount, n-1);
        return ans;
        // if(amount)
        // vector<int> prev(amount+1,0);
        // prev[0] = 1;
        // if(coins[0]%amount==0) prev[coins[0]] = coins[0]/amount;
        // for(int i=1;i<n;i++){
        //     vector<int> curr(amount+1, 0);
        //     for(int j=0;j<=amount;j++){
        //         int np = prev[amount];
        //         int p = 0;
        //         if(coins[])
        //     }
        // } 
    }
};
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
        // if(coins.empty()) return 0;
        // vector<long long> prev(amount+1,0);
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0){
        //         prev[i] = 1;
        //     }
        // }
        // for(int i=1;i<n;i++){
        //     vector<long long> curr(amount+1, 0);
        //     for(int j=0;j<=amount;j++){
        //         long long np = prev[j];
        //         long long p = 0;
        //         if(coins[i]<=j){
        //             p = curr[j-coins[i]];
        //         }
        //         curr[j] = np+p;
        //     }
        //     prev = curr;
        // }
        // return  (int)prev[amount];

        // return dp[amount];
    }
};
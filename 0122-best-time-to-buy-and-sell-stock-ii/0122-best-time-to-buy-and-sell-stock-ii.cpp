class Solution {
public:
    // int f(vector<int>& arr, int ind, int buy, int n, vector<vector<int>>& dp){
    //     if(ind == n){
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy){
    //         dp[ind][buy] = max(-arr[ind] + f(arr,ind+1,0,n,dp), f(arr,ind+1, 1, n,dp));
    //     }else{
    //         dp[ind][buy] = max(arr[ind] + f(arr,ind+1,1,n,dp), f(arr, ind+1, 0,n,dp));
    //     }
    //     return dp[ind][buy];
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        dp[n][0] = 0;
        dp[n][1] =0;
        // return f(prices, 0, 1, n, dp);
        vector<long> next(2,0); 
        for(int i=n-1;i>=0;i--){
            vector<long> curr(2,0);
            for(int j=0;j<=1;j++){
                int profit =0;
                if(j==1){
                    profit = max(-prices[i] + next[0], next[1]);
                }else{
                    profit = max(prices[i] + next[1], next[0]);
                }
                curr[j] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};
class Solution {
public:
    int f(vector<int>& arr, int ind, int buy, int n, vector<vector<int>>& dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            dp[ind][buy] = max(-arr[ind] + f(arr,ind+1,0,n,dp), f(arr,ind+1, 1, n,dp));
        }else{
            dp[ind][buy] = max(arr[ind] + f(arr,ind+1,1,n,dp), f(arr, ind+1, 0,n,dp));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(prices, 0, 1, n, dp);

    }
};
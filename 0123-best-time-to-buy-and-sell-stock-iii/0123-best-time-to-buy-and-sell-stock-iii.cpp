class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int c, int n, vector<vector<vector<int>>>& dp){
        if(ind == n|| c>1){
            return 0;
        }
        if(dp[ind][buy][c]!=-1) return dp[ind][buy][c];
        int profit;
        if(buy){
            profit = max(-prices[ind] + f(prices,ind+1,0,c,n,dp), f(prices, ind+1,1,c,n,dp));
        }else{
            profit = max(prices[ind] + f(prices,ind+1,1,c+1,n,dp), f(prices,ind+1,0,c,n,dp));
        }
        return dp[ind][buy][c] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        // return f(prices, 0, 1, 0, n, dp);
        vector<vector<int>> next(2, vector<int>(3,0));
        int profit;
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2, vector<int>(3,0));
            for(int j=0;j<2;j++){
                for(int k=1;k<=2;k++){
                    if(j==1){
                        profit = max(-prices[i] + next[0][k], next[1][k]);
                    }else{
                        profit = max(prices[i] + next[1][k-1], next[0][k]);
                    }
                    curr[j][k] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};
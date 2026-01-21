class Solution {
public:
    int compute(int n, vector<int>& cost){
        if(n<0) return 0;
        if(n==0) return cost[0];
        int pick = cost[n] + compute(n-2,cost);
        int npick = 0 + compute(n-1,cost);
        return min(pick,npick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            dp[i] = cost[i];
            if(i<n-1){
                dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
            }
        }
        return min(dp[0],dp[1]);
    }
};
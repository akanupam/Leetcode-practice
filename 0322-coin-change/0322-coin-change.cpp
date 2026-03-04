class Solution {
public:
    // int f(vector<int>& arr, int target, int i, vector<vector<int>>& dp){
    //     if(i==0){
    //         if(target%arr[0]==0) return target/arr[0];
    //         else return 1e9;
    //     }
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     int nottake = 0 + f(arr, target, i-1,dp);
    //     int take = INT_MAX;
    //     if(arr[i]<=target){
    //         take = 1 + f(arr,target-arr[i],i,dp);
    //     }
    //     return dp[i][target] = min(take,nottake);
    // }
    int coinChange(vector<int>& arr, int target) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target+1,0));
        vector<int> prev(target+1,0);
        // for(int T=0;T<=target;T++){
        //     if(T%arr[0]==0) {
        //         dp[0][T] = T/arr[0];
        //     }else{
        //         dp[0][T] = INT_MAX;
        //     }
        // }
        for(int i=0;i<=target;i++){
            if(i%arr[0]==0) prev[i] = i/arr[0];
            else prev[i] = INT_MAX;
        }

        for(int i=1;i<n;i++){
            vector<int> curr(target+1,0);
            for(int T=0;T<=target;T++){
                int nottake = 0 + prev[T];
                int take = 1e9;
                if(arr[i]<=T){
                    take = 1+ curr[T-arr[i]];
                }
                curr[T] = min(take,nottake);
            }
            prev = curr;
        }

        // int ans = f(arr,target,n-1,dp);
        // int ans = dp[n-1][target];
        int ans = prev[target];
        if(ans>=1e9) return -1;
        return ans;
    }
};
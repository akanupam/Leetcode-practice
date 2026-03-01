class Solution {
public:
    // bool f(vector<int>& arr, int rem, int i,vector<vector<int>>& dp){
    //     if(rem==0) return true;
    //     if(i==0) return dp[i][rem]= (rem==arr[i]);
    //     if(dp[i][rem] != -1) return dp[i][rem];
    //     bool np =  f(arr,rem,i-1,dp);
    //     bool p = false;
    //     if(arr[i]<=rem){
    //         p = f(arr,rem-arr[i],i-1,dp);
    //     }
    //     return dp[i][rem] = np||p;
    // }
    bool canPartition(vector<int>& nums) {
        int rem = 0;
        for(int i=0;i<nums.size();i++){
            rem += nums[i];
        }
        if(rem%2!=0) return false;
        rem = rem/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(rem+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0] = true;
        }
        if(nums[0]<=rem){
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=rem;j++){
                bool np = dp[i-1][j];
                bool p = false;
                if(nums[i]<=j){
                    p = dp[i-1][j-nums[i]];
                }
                dp[i][j] = np||p;
            }
        }

        return dp[nums.size()-1][rem];
    }
};
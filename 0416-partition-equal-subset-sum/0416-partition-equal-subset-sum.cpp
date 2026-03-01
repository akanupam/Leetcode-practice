class Solution {
public:
    bool f(vector<int>& arr, int rem, int i,vector<vector<int>>& dp){
        if(rem==0) return true;
        if(i==0) return dp[i][rem]= (rem==arr[i]);
        if(dp[i][rem] != -1) return dp[i][rem];
        bool np =  f(arr,rem,i-1,dp);
        bool p = false;
        if(arr[i]<=rem){
            p = f(arr,rem-arr[i],i-1,dp);
        }
        return dp[i][rem] = np||p;
    }
    bool canPartition(vector<int>& nums) {
        int rem = 0;
        for(int i=0;i<nums.size();i++){
            rem += nums[i];
        }
        if(rem%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(rem+1,-1));
        return f(nums,rem/2,nums.size()-1,dp);
    }
};
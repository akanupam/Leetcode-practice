class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), hash(n,-1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
        }
        int maxInd=0, maxLen=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxLen){
                maxLen = dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        int i=maxInd;
        while(i!=-1){
            ans.push_back(nums[i]);
            i = hash[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
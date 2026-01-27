class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int w_sum = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            w_sum += nums[i];
            ans = max(w_sum, ans);
            if(w_sum< 0){
                w_sum = 0;
            }
        }
        // if(ans)
        return ans;
    }
};
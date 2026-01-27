class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // int res=INT_MIN;
        // int n = nums.size();
        // for(int j =0;j<nums.size();j++){
        //     int w_sum = 0;
        //     int ans = INT_MIN;
        //     for(int i=j;i<nums.size()+j;i++){
        //     int ind = i;
        //     if(i>=n) {
        //         ind= (i + 1) % n;
        //     } 
        //     w_sum += nums[ind];
        //     ans = max(w_sum, ans);
        //     if(w_sum< 0){
        //         w_sum = 0;
        //     }
        //     }
        //     res= max(res,ans);
        // }
        // return res;

        int maxsum,minsum = nums[0];
        int currmin, currmax = 0;
        int total=0;
        for(int x: nums){
            currmax = max(x, currmax+x);
            maxsum = max(maxsum,currmax);

            currmin = min(x, currmin +x);
            minsum = min(minsum, currmin);

            total += x;
        }
        if(maxsum<0) return maxsum;
        return max(maxsum, total-minsum);

    }
};
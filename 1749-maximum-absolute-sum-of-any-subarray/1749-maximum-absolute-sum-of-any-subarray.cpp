class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = nums[0];
        int ans2 = nums[0];
        int sum = 0;
        for(int num:nums){
            sum = max(num, sum+num);
            ans1 = max(sum,ans1);
        }
        sum=0;
        for(int num:nums){
            sum = min(num, sum+num);
            ans2 = min(sum,ans2);
        }
        return max(abs(ans2),ans1);
    }
};
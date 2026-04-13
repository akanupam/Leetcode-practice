class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) xorr = xorr^nums[i];
        long rightmost = (xorr^xorr-1) & xorr;
        int n1= 0, n2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & rightmost){
                n1 = n1^nums[i];
            }else{
                n2 = n2^nums[i];
            }
        }
        return {n1,n2};
    }
};
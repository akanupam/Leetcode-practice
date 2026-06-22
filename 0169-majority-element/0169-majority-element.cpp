class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 0;
        for(int num:nums){
            if(count==0){
                major=num;
            }
            if(num==major){
                count++;
            }else{
                count--;
            }
        }
        return major;
    }
};
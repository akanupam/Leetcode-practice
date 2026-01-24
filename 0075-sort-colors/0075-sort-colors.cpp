class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p1 = 0;
        int p2 = nums.size()-1;
        while(p1<=p2){
            if(nums[p1]==1){
                p1++;
            }else if(nums[p1]==0){
                swap(nums[p0],nums[p1]);
                p1++;
                p0++;
            }else{
                swap(nums[p2],nums[p1]);
                p2--;
            }
        }
    }
};
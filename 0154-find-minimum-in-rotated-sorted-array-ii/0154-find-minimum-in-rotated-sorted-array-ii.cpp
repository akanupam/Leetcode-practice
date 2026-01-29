class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1;
        // int ans= INT_MAX;
        while(l<r){
            int mid = (l+r)/2;
            // ans = min(nums[mid],ans);
            
            if(nums[mid] < nums[r]){
                r = mid;
            }else if(nums[mid] == nums[r]){
                r--;
            }
            else{
                l= mid+1;
            }
        }
        return nums[l];
    }
};
class Solution {
public:
    int func(vector<int>& nums, int k){
        int n = nums.size();
        map<int, int> mpp;
        int i=0;
        int cnt=0;
        for(int j=0;j<n;j++){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            cnt  += j-i+1;    
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};
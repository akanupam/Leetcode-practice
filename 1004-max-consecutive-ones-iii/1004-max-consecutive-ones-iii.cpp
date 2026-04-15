class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                while(k==0){
                    if(nums[i]==0){
                        k++;
                    }
                    i++;
                }
                k--;
            }
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};
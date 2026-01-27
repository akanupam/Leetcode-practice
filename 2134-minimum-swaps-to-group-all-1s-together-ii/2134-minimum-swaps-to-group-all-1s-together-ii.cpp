class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int win_len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) win_len ++;
        }
        int zeros = 0;
        for(int i=0;i<win_len;i++){
            if(nums[i]==0) zeros++;
        }
        int ans = zeros;
        vector<int> num = nums;
        for(int i=0;i<nums.size();i++){
            num.push_back(nums[i]);
        }
        int n = num.size();
        for(int i=win_len;i<n;i++){
            int ind = i;
            if(num[ind]==0 && num[ind-win_len]==1){
                zeros++;
            }else if(num[ind]==1 && num[ind-win_len]==0){
                zeros--;
            }
            ans = min(zeros,ans);
        }
        return ans;

    }
};
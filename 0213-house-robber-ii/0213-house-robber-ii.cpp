class Solution {
public:
    int f(vector<int>& arr){
        if(nums.size()==0) return 0;
        if(nums.size() == 1){
            return nums[0];
        }
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;
        for(int i=0;i<n;i++){
            int pick = arr[i] ;
            if(i>1) pick += prev2;
            int npick = 0 + prev;
            prev2 = prev;
            prev = max(pick,npick);
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1),f(temp2));
    }
};
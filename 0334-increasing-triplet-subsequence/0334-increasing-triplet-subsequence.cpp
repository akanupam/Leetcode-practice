class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        // for(int i=0;i<n-2;i++){
        //     int f = nums[i];

        //     for(int j=i+1;j<n-1;j++){
        //         int s = nums[j];
        //         if(f>s) continue;
        //         for(int k=j+1;k<n;k++){
        //             int t = nums[k];
        //             if(s>t) {
        //                 continue;
        //             }else{
        //                 return true;
        //             }
        //         }
        //     }
        // }
        int first = INT_MAX;
        int second = INT_MAX;
        for(int i=0;i<n;i++){
            if(first >= nums[i]){
                first = nums[i];
            }else if(second >= nums[i]){
                second = nums[i];
            }else{
                return true;
            }
        }
        return false; 
    }
};
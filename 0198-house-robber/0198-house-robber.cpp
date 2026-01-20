class Solution {
public:
    int f(int i, vector<int>& visited, vector<int>& arr){
        if(i==0) return arr[0];
        if(i<0) return 0;
        if(visited[i]!=0){
            return visited[i];
        }
        int pick = arr[i] + f(i-2, visited, arr);
        int npick = 0 + f(i-1,visited, arr);
        visited[i] = max(pick,npick);
        return visited[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int ans;
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i] + prev2;
            int npick = 0 + prev;
            ans = max(pick,npick);
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};
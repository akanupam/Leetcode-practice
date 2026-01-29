class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int ans = INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            ans = min(arr[mid],ans);
            if( arr[mid] >= arr[r]){
                l = mid + 1;
            }else{
                r = mid -1;
            }
        }
        return ans;
    }
};
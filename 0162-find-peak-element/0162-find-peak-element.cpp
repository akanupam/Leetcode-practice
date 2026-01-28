class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        // int n = arr.size();
        // int INF = INT_MAX;
        // arr[-1] = -INF;
        // arr[r+1] = -INF;
        // if(n==1) return 0;
        // if(n==2){
        //     if(arr[0]>arr[1]) return 0;
        //     if(arr[1]>arr[0]) return 1;
        // }
        // if(arr[0]>arr[1]) return 0;
        // if(arr[n-2]<arr[n-1]) return n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};
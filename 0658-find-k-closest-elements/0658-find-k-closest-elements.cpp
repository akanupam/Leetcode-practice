class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int left = 0;
        // int right = arr.size() - k;

        // while (left < right) {
        //     int mid = left + (right - left) / 2;

        //     if (x - arr[mid] > arr[mid + k] - x)
        //         left = mid + 1;
        //     else
        //         right = mid;
        // }

        // return vector<int>(arr.begin() + left, arr.begin() + left + k);


        priority_queue<pair<int,int>> pq;
        for(auto num: arr){
            pq.push({abs(num-x),num});
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
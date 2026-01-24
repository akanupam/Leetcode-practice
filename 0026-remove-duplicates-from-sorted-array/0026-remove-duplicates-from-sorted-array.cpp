class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int p  =0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] != arr[p]){
                p++;
                arr[p] = arr[i];
            }
        }
        return p+1;
    }
};
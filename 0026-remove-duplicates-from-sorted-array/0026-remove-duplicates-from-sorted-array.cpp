class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int p  =0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[p]){
                continue;
            }
            if(arr[p]<arr[i]){
                p++;
                arr[p] = arr[i];
            }else{
                break;
            }
        }
        return p+1;
    }
};
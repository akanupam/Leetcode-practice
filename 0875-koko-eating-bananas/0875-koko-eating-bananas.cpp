class Solution {
public:
    int max_element(vector<int>& piles){
        int m = 0;
        for(int i=0;i<piles.size();i++){
            m = max(piles[i],m);
        }
        return m;
    }
    long long check(vector<int>& piles, int m){
        long long temp = 0;
        for(int i=0;i<piles.size();i++){
            temp += ceil((double)piles[i]/(double)m);
        }
        return temp;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = max_element(piles);
        while(l<=r){
            int mid = (l+r)/2;
            long long ch = check(piles,mid);
            if(ch<=h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
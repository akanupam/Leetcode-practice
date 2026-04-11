class Solution {
public:
    int minBitFlips(int start, int end) {
        int c=0;
        while(start>0 || end>0){
            if(start%2 != end%2){
                c++;
            }
            start/=2;
            end/=2;
        }
        return c;
    }
};
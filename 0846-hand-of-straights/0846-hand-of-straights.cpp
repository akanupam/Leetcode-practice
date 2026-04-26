class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> freq;
        for(int num:hand){
            freq[num]++;
        }
        for(auto& it: freq){
            int num = it.first;
            int count = it.second;
            if(count > 0){
                for(int i=0;i<groupSize;i++){
                    if(freq[num + i] < count) return false;
                    freq[num + i] -= count;
                }
            }
        }
        return true;
    }
};
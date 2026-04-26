class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(char c:tasks){
            mpp[c]++;
        }
        priority_queue<int> maxHeap;
        for(auto it: mpp){
            maxHeap.push(it.second);
        }
        int time = 0;
        while(!maxHeap.empty()){
            vector<int> temp;
            int cycle = n + 1;
            int i = 0;
            while(i<cycle && !maxHeap.empty()){
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;
                if(cnt > 0) temp.push_back(cnt);
                time++;
                i++;
            }
            for(int val:temp){
                maxHeap.push(val);
            }
            if(maxHeap.empty()) break;
            time += (cycle - i);
        }
        return time;
    }
};
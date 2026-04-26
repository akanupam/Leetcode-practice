class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> freq;
        for (int num : nums) freq[num]++;
        for (auto& it : freq) {
            int num = it.first;
            int count = it.second;
            if (count > 0) {
                for (int i = 0; i < k; i++) {
                    if (freq[num + i] < count) return false;
                    freq[num + i] -= count;
                }
            }
        }
        return true;
    }
};
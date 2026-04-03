
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {robots[i], distance[i]};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            robots[i] = a[i].first;
            distance[i] = a[i].second;
        }

        sort(walls.begin(), walls.end());

        auto countWalls = [&](int l, int r) -> int {
            if (l > r) return 0;
            return (int)(upper_bound(walls.begin(), walls.end(), r) -
                         lower_bound(walls.begin(), walls.end(), l));
        };

        vector<int> cntL(n), cntR(n);

        for (int i = 0; i < n; i++) {
            int r = robots[i], d = distance[i];

            int leftBound = r - d;
            if (i > 0) leftBound = max(leftBound, robots[i - 1] + 1);
            cntL[i] = countWalls(leftBound, r);

            int rightBound = r + d;
            if (i < n - 1) rightBound = min(rightBound, robots[i + 1] - 1);
            cntR[i] = countWalls(r, rightBound);
        }

        vector<int> overlap(n, 0);
        for (int i = 1; i < n; i++) {
            int l = max(robots[i - 1], robots[i] - distance[i]);
            int r = min(robots[i - 1] + distance[i - 1], robots[i] - 1);
            if (l <= r) overlap[i] = countWalls(l, r);
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = cntL[0];
        dp[0][1] = cntR[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0] + cntL[i],
                           dp[i - 1][1] + cntL[i] - overlap[i]);

            dp[i][1] = max(dp[i - 1][1] + cntR[i],
                           dp[i - 1][0] + cntR[i]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;

        vector<int> unique;
        for (auto& [k, v] : freq) unique.push_back(k);
        sort(unique.begin(), unique.end());

        int n = unique.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long gain = unique[i] * freq[unique[i]];

            // Find last compatible index j such that unique[i] - unique[j] > 2
            int j = lower_bound(unique.begin(), unique.end(), unique[i] - 2) - unique.begin() - 1;

            if (j >= 0)
                gain += dp[j];

            dp[i] = max((i > 0 ? dp[i - 1] : 0LL), gain);
        }

        return dp.back();
    }
};

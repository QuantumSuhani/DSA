#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int ans = 0;
        int cur = 1;        // length of current strictly increasing segment (ending at i)
        int prev = 0;       // length of the previous strictly increasing segment
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                // we end the current increasing run; shift to prev
                prev = cur;
                cur = 1;
            }
    
            ans = max(ans, cur / 2);
            ans = max(ans, min(prev, cur));
        }
        return ans;
    }
};

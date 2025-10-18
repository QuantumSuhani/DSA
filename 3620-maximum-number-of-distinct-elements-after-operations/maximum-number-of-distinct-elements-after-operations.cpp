class Solution {
public:
    int maxDistinctElements(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long occupied = LLONG_MIN;  // tracks the last assigned value

        for (long long x : nums) {
            // If even the max allowed (x + k) is <= occupied, we can't pick a new distinct for this x
            if (occupied < x + k) {
                long long lo = x - k;
                long long candidate = max(lo, occupied + 1);
                // assign this new distinct value
                occupied = candidate;
                ans++;
            }
        }
        return ans;
    }
};

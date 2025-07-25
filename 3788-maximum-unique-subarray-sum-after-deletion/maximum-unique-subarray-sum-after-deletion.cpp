class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if (mx <= 0) return mx;

        unordered_set<int> seen;
        int sum = 0;
        for (int num : nums) {
            if (num >= 0 && seen.find(num) == seen.end()) {
                sum += num;
                seen.insert(num);
            }
        }
        return sum;
    }
};
   


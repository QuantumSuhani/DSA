class Solution {
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;  // tolerance check
        }

        // try all pairs (avoid duplicate by fn < sn)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> next;
                
                // baki numbers push karo (i, j ke alawa)
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // possible results (optimised: commutative duplication avoid)
                vector<double> results = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6) results.push_back(a / b);
                if (fabs(a) > 1e-6) results.push_back(b / a);

                // har result try karo
                for (double val : results) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};

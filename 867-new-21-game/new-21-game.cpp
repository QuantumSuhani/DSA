#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Quick cases:
        // If k == 0, Alice never draws and stays at 0 => always <= n.
        // If n >= k - 1 + maxPts, even if she draws maxPts at last step, she'll still be <= n => probability 1.
        if (k == 0 || n >= k - 1 + maxPts) 
            return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;                   // Starting point
        double windowSum = 1.0;       // Sum of dp values within the sliding window
        double result = 0.0;          // Final probability for outcomes >= k and <= n

        // Build up dp values from 1 to n
        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // Alice will continue drawing, so include dp[i] in window
                windowSum += dp[i];
            } else {
                // Alice stops here; count this toward the result
                result += dp[i];
            }

            // Maintain window: remove dp[i - maxPts] if it's out of range
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};

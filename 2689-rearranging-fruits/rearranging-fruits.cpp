class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> count;
        int n = basket1.size();
        
        for (int i = 0; i < n; i++) {
            count[basket1[i]]++;
            count[basket2[i]]--;
        }
        
        vector<int> toSwap;
        int minFruit = INT_MAX;
        
        for (auto& [val, diff] : count) {
            if (diff % 2 != 0) return -1;  // Can't balance odd counts
            
            int times = abs(diff) / 2;
            for (int i = 0; i < times; ++i)
                toSwap.push_back(val);
            
            minFruit = min(minFruit, val);
        }
        
        sort(toSwap.begin(), toSwap.end());
        
        long long cost = 0;
        for (int i = 0; i < toSwap.size() / 2; i++) {
            cost += min(toSwap[i], 2 * minFruit);
        }
        
        return cost;
    }
};

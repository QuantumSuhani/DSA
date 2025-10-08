#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
       
        std::sort(potions.begin(), potions.end());
        
        std::vector<int> pairs(n);
        
        for (int i = 0; i < n; ++i) {
            long long spell_strength = spells[i];
            
           
            long long required_min_strength = (success + spell_strength - 1) / spell_strength;
            
            auto it = std::lower_bound(potions.begin(), potions.end(), required_min_strength);
            
           
            int num_successful_potions = std::distance(it, potions.end());
            
            pairs[i] = num_successful_potions;
        }
        
        return pairs;
    }
};
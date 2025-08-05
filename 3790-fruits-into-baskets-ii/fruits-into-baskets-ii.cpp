#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> used(n, false);
        int unplaced = 0;

        for (int fruit : fruits) {
            bool placed = false;
            for (int i = 0; i < n; i++) {
                if (!used[i] && fruit <= baskets[i]) {
                    used[i] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};


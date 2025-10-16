#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;

        // Step 1: Count the frequency of each remainder (mod class)
        for (int x : nums) {
            int r = ((x % value) + value) % value; // handle negative numbers
            count[r]++;
        }

        // Step 2: Try forming numbers starting from 0, 1, 2, ...
        for (int i = 0; ; i++) {
            int r = i % value;
            if (count[r] == 0)
                return i; // smallest number we cannot form → MEX
            count[r]--; // use one occurrence of that remainder
        }
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> freq;
        for (char ch : s) {
            freq[ch]++;   // har character ka count
        }

        unordered_set<char> vowels = {'a','e','i','o','u'};
        int maxVowel = 0, maxConsonant = 0;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char c = it->first;
            int cnt = it->second;
            if (vowels.count(c)) {
                maxVowel = max(maxVowel, cnt);
            } else {
                maxConsonant = max(maxConsonant, cnt);
            }
        }

        return maxVowel + maxConsonant;   // ✅ yeh ab function ke andar hai
    }
};


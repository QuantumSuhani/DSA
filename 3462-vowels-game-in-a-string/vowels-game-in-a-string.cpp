class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;   // Found a vowel
            }
        }
        return false;  // No vowel found
    }
};

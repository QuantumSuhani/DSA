class Solution {
private:
    bool isValid(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    char toLowerCase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a';
        }
        return ch;
    }

public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            while (start < end && !isValid(s[start])) start++;
            while (start < end && !isValid(s[end])) end--;

            // Compare lowercase versions
            if (toLowerCase(s[start]) != toLowerCase(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

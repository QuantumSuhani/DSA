class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
            } // Negative numbers and 0 are not powers of two
        while (n % 2 == 0) {
            n =n/ 2;
        }
        return n == 1; // After dividing fully by 2, only 1 is a power of two
    }
};

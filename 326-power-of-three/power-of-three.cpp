class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;  // Negative numbers and zero are not powers of three
        }

        while (n % 3 == 0) {
            n = n / 3;  // Keep dividing by 3
        }

        // After the loop, check if n became 1
        if (n == 1) {
            return true;
        } 
        else {
            return false;
        }
    }
};

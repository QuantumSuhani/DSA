class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; // 0 aur negative numbers power of two nahi hote
        }

        while (n % 2 == 0) {
            n = n / 2; // n ko divide karte raho jab tak 2 se divisible hai
        }

        // Ab check karte hain ki n 1 hai ya nahi
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};

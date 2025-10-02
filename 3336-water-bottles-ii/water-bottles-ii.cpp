class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {  // renamed here
        int totalDrank = 0;
        int emptyBottles = 0;
        
        while (numBottles > 0) {
            // Drink all full bottles
            totalDrank += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            
            // Exchange empty bottles if possible
            if (emptyBottles >= numExchange) {
                numBottles = 1;           // Get 1 full bottle per exchange
                emptyBottles -= numExchange;
                numExchange += 1;         // Increase numExchange after each exchange
            } else {
                break;                    // Cannot exchange anymore
            }
        }
        
        return totalDrank;
    }
};

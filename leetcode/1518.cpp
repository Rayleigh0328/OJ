class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int full = 0;
        int empty = numBottles;
        while (empty >= numExchange){
            full += empty / numExchange;
            empty = empty % numExchange;
            result += full;
            empty += full;
            full = 0;
        }
        return result;
    }
};

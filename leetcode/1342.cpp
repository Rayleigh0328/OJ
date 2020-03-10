class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        while (num > 0){
            ++result;
            if (num & 1) --num;
            else num /= 2;
        }
        return result;
    }
};

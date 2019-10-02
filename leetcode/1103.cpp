class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int count = 1;
        vector<int> a(n,0);
        int to_give;
        while (candies > 0){
            to_give = min(candies, count);
            a[(count++ -1 + n) % n] += to_give;
            candies -= to_give;
        }
        return a;
    }
};

class Solution {
    
    // x + y = b
    // 2x + 4y = a
    // x = (4b-a)/2
    // y == (a-2b)/2
     
public:
    vector<int> numOfBurgers(int a, int b) {
        int x, y;
        int tmp =  4*b-a;
        if (tmp & 1) return {};
        else y = tmp / 2;
        
        tmp = (a-2*b);
        if (tmp & 1) return {};
        else x = tmp / 2;
        
        if (x < 0 || y < 0) return {};
        return {x,y};
    }
};

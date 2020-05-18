class Solution {
    int gcd(int x, int y){
        if (x % y == 0) return y;
        else return gcd(y, x%y);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for (int y=1;y<=n;++y)
            for (int x=1;x<y;++x)
                if (gcd(x,y) == 1){
                    result.push_back(to_string(x) + '/' + to_string(y));
                }
        return result;
    }
};

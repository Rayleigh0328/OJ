class Solution {
    
    const double eps = 1e-8;
    
public:
    vector<int> constructRectangle(int area) {
        int x = sqrt(area) + eps;
        for (int i=x;i>=1;--i)
            if (area % i == 0) return {area / i, i};
        return {};
    }
};

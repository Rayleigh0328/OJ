class Solution {
    
    int count(int x){
        int result = 0;
        while (x > 0){
            ++result;
            x -= (x & -x);
        }
        return result;
    }
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int &x, const int &y){
            int cx = count(x);
            int cy = count(y);
            if (cx < cy) return true;
            if (cy < cx) return false;
            return (x < y);
        });
        return arr;
    }
};

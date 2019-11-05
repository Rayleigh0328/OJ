class Solution {
    
    int count(int speed, const vector<int>&a){
        int ans = 0;
        for (auto x : a){
            if (x % speed==0)
                ans += x / speed;
            else 
                ans += x / speed + 1;
        }
        return ans;
    }
    
public:
    int minEatingSpeed(vector<int>& a, int H) {
        int left = 1, right = (1<<30), mid;
        while (left < right){
            if (left+1 == right) return left;
            if (left+2 == right) {
                if (count(left, a)<=H) return left;
                return left+1;
            }
            
            mid = left + ((right-left)>>1);
            if (count(mid, a)>H) left = mid + 1;
            else right = mid+1;
        }
        return left;
    }
};

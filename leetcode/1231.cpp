class Solution {
    
    bool check(int target, const vector<int>& a, int count){
        // check if a can be divided into count part and each with sum >= target
        int current_sum = 0;
        int total_count = 0;
        for (auto e : a){
            current_sum += e;
            if (current_sum >= target){
                ++total_count;
                current_sum = 0;
            }
        }
        return (total_count >= count);
    }
    
public:
    int maximizeSweetness(vector<int>& a, int k) {
        int sum = 0;
        for (auto e : a) sum += e;
        if (k==0) return sum;
        int left = 1, right =sum+1;
        int mid;
        while (left < right){
            // cout << left << " " <<right << endl;
            if (left+1 == right) return left;
            if (left+2 == right){
                if (check(left+1,a,k+1)) return left+1;
                else return left;
            }
            mid = left + (right-left) /2;
            if (check(mid,a,k+1)) left = mid;
            else right = mid;
        }
        return -1;
    }
};

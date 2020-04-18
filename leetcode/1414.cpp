class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> a;
        a.push_back(1); 
        a.push_back(1);
        
        int tmp;
        while (a.back() < k){
            tmp = a[a.size()-1] + a[a.size()-2];
            a.push_back(tmp);
        }
        
        // for (auto x : a) printf("%d ", x);
        int result = 0;
        while (k > 0){
            auto it = lower_bound(a.begin(), a.end(), k);
            if (*it > k) --it;
            k -= *it;
            ++result;
        }
        
        return result;
    }
};

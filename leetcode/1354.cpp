class Solution {
    long long get_max(multiset<long long, greater<long long>> &s){
        return *s.begin();
    }
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        for (auto x : target) sum += x;
        
        multiset<long long, greater<long long>> ms;
        for (auto x : target) ms.emplace(x);
        
        long long largest;
        while ((largest = get_max(ms)) > 1){
            ms.erase(ms.begin());
            if (2 * largest <= sum) return false;
            ms.emplace(2*largest - sum);
            sum = largest;
        } 
        return true;
    }
};

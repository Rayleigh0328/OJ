class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,greater<int>> s;
        for (auto x : stones) s.emplace(x);
        while (s.size() >= 2){
            auto it = s.begin();
            int x = *it;
            s.erase(it);
            it = s.begin();
            int y = *it;
            s.erase(it);
            printf("%d, %d\n", x, y);
            if (x - y > 0) s.emplace(x-y);
        }
        if (s.empty()) return 0;
        return *s.begin();    }
};

class Solution {
    // pair of (id, size)
    typedef pair<int, int> MyPair;
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<MyPair> a;
        for (int i=0;i<groupSizes.size();++i)
            a.push_back(MyPair(i, groupSizes[i]));
        sort(a.begin(), a.end(), [](const MyPair &x, const MyPair &y){return x.second < y.second;});
        vector<vector<int>> result;
        int p1 = 0, p2;
        while (p1  < a.size()){
            vector<int> current_group;
            for (int i=0;i<a[p1].second;++i)
                current_group.push_back(a[p1+i].first);
            result.push_back(current_group);
            p1 = p1 + a[p1].second;
        }
        return result;
    }
};

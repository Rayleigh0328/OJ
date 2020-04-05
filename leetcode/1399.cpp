class Solution {
    int get_key(int k){
        int result = 0;
        while (k > 0){
            result += k % 10;
            k /= 10;
        }
        return result;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> count;
        for (int i=1;i<=n;++i) ++count[get_key(i)];
        int max_size = 0;
        for (auto &e : count)
            if (e.second > max_size) max_size = e.second;
        int result = 0;
        for (auto &e : count)
            if (e.second == max_size) ++result;
        return result;
    }
};

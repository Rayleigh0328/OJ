class Solution {
public:
    int totalFruit(vector<int>& a) {
        int p1 = 0, p2=0;
        int result = 0;
        unordered_map<int, int> count;
        while (p2 < a.size()){
            ++count[a[p2++]];
            if (count.size() > 2){
                int x = a[p1++];
                if (count[x] == 1) count.erase(x);
                else --count[x];
            }
            result = max(result, p2-p1);
        }
        return result;
    }
};

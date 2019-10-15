class Solution {
public:
    bool isPossible(vector<int>& a) {
        map<int,int> value_count;
        for (int e : a)
            if (value_count.find(e) == value_count.end()) value_count[e] = 1;
            else ++value_count[e];
        
        int prev = -(1<<30);
        int count1, count2, count3;
        count1=count2=count3=0;
        
        for (auto e : value_count){
            int value = e.first;
            int count = e.second;
            if (prev < value - 1) {
                if (count1 > 0 || count2 > 0) return false;
                count3=0;
                count1=count;
            }
            else {
                if (count < count1 + count2) return false;
                int rest = count - count1 - count2;
                int cp1 = count1;
                int cp2 = count2;
                int cp3 = count3;
                if (rest > cp3) count1 = rest - cp3;
                else {
                    count3 = rest;
                    count1 = 0;
                }
                count3 += cp2;
                count2 = cp1;
            }
            prev = value;
        }
        return (count1==0 && count2==0);
    }
};

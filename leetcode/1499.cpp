class Solution {
    
    const int inf = (1<<28);
    
    int get_value(vector<int>& point){
        return point[1] - point[0];
    }
    
    int get_max(multiset<int> &ms){
        if (ms.empty()) return -inf;
        return *ms.rbegin();
    }
    
    void remove(multiset<int> &ms, int value){
        ms.erase(ms.find(value));
    }
    
public:
    int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        multiset<int> ms;
        
        int result = -inf;
        int left = 0;
        for (int i=0;i<a.size();++i){
            while (a[i][0] - a[left][0]>k){
                remove(ms, get_value(a[left++]));
            }
            result = max(result, a[i][0] + a[i][1] + get_max(ms));
            ms.emplace(get_value(a[i]));
        }
        return result;
    }
};

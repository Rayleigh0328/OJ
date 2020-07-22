class Solution {
    
    const int inf = (1<<28);
    typedef pair<int,int> RangeType;
    
    vector<RangeType> a;
    
    vector<string> construct_answer(const string &s, vector<RangeType>&r){
        vector<string> result;
        for (auto &range : r)
            result.push_back(s.substr(range.first, range.second - range.first + 1));
        return result;
    }
    
    bool is_overlap(RangeType &x, RangeType &y){
        return (y.first <= x.first && x.first <= y.second) || (y.first <= x.second && x.second <= y.second);
    }
    
    bool is_contain(RangeType &x, RangeType &y){
        return (x.first <= y.first && y.second <= x.second);
    } 
    
    RangeType merge(RangeType &x, RangeType &y){
        return RangeType(min(x.first, y.first), max(x.second, y.second));
    }
    
    void construct_ranges(const string &s){
        unordered_map<char, RangeType> mp;
        
        // get range for each character
        for (int i=0;i<s.size();++i){
            if (mp.find(s[i]) == mp.end()) mp[s[i]] = RangeType(inf, -1);
            RangeType &range = mp[s[i]];
            range.first = min(range.first,i);
            range.second = max(range.second, i);
        }
        
        for (auto &e : mp){
            printf("%c:(%d,%d)\n", e.first, e.second.first, e.second.second);
        }
        
        // extend range for each character
        // e.g. "abacb", merge the range of "a" with range of "b"
        vector<pair<int,int>> tmp;
        for (auto &e : mp)
            tmp.push_back(pair<int,int>(e.first, e.second.first));
        sort(tmp.begin(), tmp.end(), [](const pair<int,int>&x, const pair<int,int>&y){
            return x.second < y.second;
        });
        
        for (int i=0;i<tmp.size();++i){
            char ch = tmp[i].first;
            printf("merge %c\n", ch);
            RangeType &range = mp[ch];
            for (int i=range.first;i<=range.second;++i)
                range = merge(range, mp[s[i]]);
        }
        
        printf("after merge\n");
        for (auto &e : mp){
            printf("%c:(%d,%d)\n", e.first, e.second.first, e.second.second);
        }
        
        // sort range by left endpiont 
        for (auto &e : mp) a.push_back(e.second);
        sort(a.begin(), a.end(), [](const RangeType &x, const RangeType &y){return x.first < y.first;});
        
        bool flag = true;
        while (flag){
            flag = false;
            for (int i=0;i<a.size();++i){
                if (flag) break;
                for (int j=i+1;j<a.size();++j)
                    if (is_contain(a[i],a[j])){
                        flag = true;
                        a.erase(a.begin() + i);
                        break;
                    }
            }
        }
        
        printf("ranges:\n");
        for (auto &range : a){
            printf("(%d, %d) ", range.first, range.second);
            printf("\n");
        }
    }
    
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        construct_ranges(s);
        
        return construct_answer(s, a);
    }
};

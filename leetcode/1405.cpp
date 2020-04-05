class Solution {
    
    static bool cmp(const pair<char,int> &x, const pair<char,int> &y){
        return x.second > y.second;
    }
    
public:
    string longestDiverseString(int x, int y, int z) {
        vector<pair<char, int>> a;
        a.push_back(pair<char,int>('a',x));
        a.push_back(pair<char,int>('b',y));
        a.push_back(pair<char,int>('c',z));
        
        string result="$";
        bool continueFlag = true;
        while (continueFlag){
            sort(a.begin(), a.end(), cmp);    
            continueFlag = false;
            if (result.back() == a[0].first){
                if (a[1].second > 0){
                    result.push_back(a[1].first);
                    --a[1].second;
                    continueFlag = true;
                }
            }
            else {
                if (a[0].second > 0){
                    result.push_back(a[0].first);
                    --a[0].second;
                    continueFlag = true;
                }
                if (a[0].second > 0){
                    result.push_back(a[0].first);
                    --a[0].second;
                    continueFlag = true;
                }
            }
        }
        return result.substr(1);
    }
};

class Solution {
    
    typedef pair<char,int> Run;
    
    int solve(char ch, const vector<Run> &a, int limit){
        int result = 0;
        int left = 0, right=0, same_count=0, diff_count=0;
        while (right<a.size() && diff_count + (a[right].first==ch?0 : a[right].second) <= limit) {
            if (a[right].first == ch) same_count += a[right].second;
            else diff_count += a[right].second;
            ++right;
        }
        // printf("char: %c, left: %d, right:%d\n", ch, left, right);
        result = max(result, same_count + limit);
        
        while (right < a.size()){
            
            if (a[right].first == ch) same_count+=a[right].second;
            else diff_count+=a[right].second;
            ++right;
            
            while (diff_count > limit){
                if (a[left].first == ch) same_count -= a[left].second;
                else diff_count -= a[left].second;
                ++left;
            }
            
            // printf("char: %c, left: %d, right:%d\n", ch, left, right);
            result = max(result, same_count + limit);
            
        }
            
        return result;
    }
    
public:
    int characterReplacement(string s, int k) {
        // run length encode s
        vector<Run> a;
        for (char ch : s){
            if (a.empty() || ch != a.back().first) a.push_back(Run(ch,1));
            else ++a.back().second;
        }
        
        int ans = 0;
        for (char ch = 'A'; ch <='Z'; ++ch)
            ans = max(ans, solve(ch, a, k));
        return min(ans, (int)s.size());
    }
};

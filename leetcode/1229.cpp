bool cmp_vector(const vector<int>& a, const vector<int>& b){
    return a[0] <= b[0];
}

    class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& a, vector<vector<int>>& b, int duration) {
        sort(a.begin(), a.end(), cmp_vector);
        sort(b.begin(), b.end(), cmp_vector);
        int p1=0;
        int p2=0;
        vector<int> ans;
        int s_a,e_a, s_b, e_b;
        while (p1 < a.size() && p2 < b.size()){
            s_a = a[p1][0];
            e_a = a[p1][1];
            s_b = b[p2][0];
            e_b = b[p2][1];
            // non overlap
            if (s_a >= e_b){
                ++p2;
                continue;
            }
            if (s_b >= e_a ){
                ++p1;
                continue;
            }
            // overlap cases
            // case 1: a contains b
            if (s_a <= s_b && e_b <= e_a) {
                if (e_b - s_b >= duration) {
                    ans.push_back(s_b);
                    ans.push_back(s_b + duration);
                    break;
                }
                else {
                    ++p2;
                    continue;
                }
            }
            // case 2: b contains a
            if (s_b <= s_a && e_a <=e_b){
                if (e_a - s_a >= duration){
                    ans.push_back(s_a);
                    ans.push_back(s_a + duration);
                    break;
                }
                else {
                    ++p1;
                    continue;
                }
            }
            
            // case 3: s_a in [s_b, e_b]
            if (s_b <= s_a && s_a <= e_b){
                if (e_b - s_a >= duration){
                    ans.push_back(s_a);
                    ans.push_back(s_a + duration);
                    break;
                }
                else {
                    ++p2;
                    continue;
                }
            }
            
            // case 4: s_b in [s_a, e_a]
            if (s_a <= s_b && s_b <= e_a){
                if (e_a - s_b >= duration){
                    ans.push_back(s_b);
                    ans.push_back(s_b+duration);
                    break;
                }
                else {
                    ++p1;
                    continue;
                }
            } 
        }
        return ans;
    }
};

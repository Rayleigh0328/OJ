class Solution {
public:

    int count_one(int x){ 
        int result = 0; 
        while ((x & -x) >0){ 
            ++result; 
            x -= (x & -x); 
        } 
        return result; 
    }

    bool solve(const vector<int> &v, int left, int right, int limit){
        int finger_print = (v[left-1] ^ v[right]);
        if ((right - left) & 1 == 0)
            return ((count_one(finger_print) - 1) / 2 <= limit);
        else 
            return (count_one(finger_print) / 2 <= limit);
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> sum;
        sum.push_back(0);
        for (int i=0; i<s.size();++i)
            sum.push_back((sum[i] ^ (1<<(s[i]-'a'))));
        vector<bool> ans;
        for (auto query : queries)
            ans.push_back(solve(sum, query[0] + 1, query[1] + 1, query[2]));
        return ans;
    }
};

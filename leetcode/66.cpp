class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //return digits;
        vector<int> ans;
        for (int i=0;i<digits.size();++i) ans.push_back(digits[i]);
        ++ans[ans.size() - 1];
        
        int c = 0;
        for (int i=ans.size()-1; i>=0; --i)
        {
            ans[i] += c;
            c = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        if (c == 1)
        {
            ans.push_back(0);
            for (int i=ans.size()-1;i>0;--i) ans[i] = ans[i-1];
            ans[0] = c;
        }
        return ans;
    }
};
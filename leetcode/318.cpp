class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int> sign;
        for (int i=0;i<words.size();++i)
        {
            int cur_sign = 0;
            for (int j=0;j<words[i].size();++j)
                cur_sign |= 1 << (words[i][j] - 'a');
            sign.push_back(cur_sign);
        }
        int ans = 0;
        for (int i=0;i<words.size();++i)
            for (int j=0;j<words.size();++j)
                if ((sign[i] & sign[j]) == 0)
                    ans = max(ans, int(words[i].length() * words[j].length()));
        return ans;
    }
};
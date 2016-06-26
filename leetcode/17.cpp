class Solution {
private:
    string keyboard[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int *d;
    int *a;
    int n;
    vector<string> ans;

private:
    void solve(int k)
    {
        if (k == -1) return;
        if (k == n)
        {
            string tmp = "";
            for (int i=0;i<n;++i)
                tmp += keyboard[d[i]][a[i]];
            ans.push_back(tmp);
            solve(k-1);
            return;
        }
        
        ++a[k];
        if (a[k] == keyboard[d[k]].size())
        {
            a[k] = -1;
            solve(k-1);
            return;
        }
        
        solve(k+1);
    }
    
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
            return vector<string>();
            
        n = digits.size();
        
        d = new int [n];
        for (int i=0;i<n;++i)
            d[i] = digits[i]-'2';
            
        a = new int [n];
        for (int i=0;i<n;++i)
            a[i] = -1;
        
        ans.clear();
        solve(0);
        
        delete [] d;
        delete [] a;
        return ans;
    }
};
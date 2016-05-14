class Solution {
private:
    bool is_operator(char ch)
    {
        return ch == '+' || ch == '*' || ch == '-';
    }
    
    int calc(int a, int b, char op)
    {
        if (op == '+') return a+b;
        if (op == '-') return a-b;
        return a*b; 
    }
    
    vector<int> solve(int left, int right, const string &s)
    {
        vector<int> ans;
        ans.clear();
        
        bool no_op = true;
        for (int i=left; i<right;++i)
            if (is_operator(s[i]))
            {
                no_op = false;
                vector<int> set1 = solve(left, i, s);
                vector<int> set2 = solve(i+1, right, s);
                for (int ind1 = 0; ind1<set1.size();++ind1)
                    for (int ind2 = 0; ind2<set2.size();++ind2)
                        ans.push_back(calc(set1[ind1], set2[ind2], s[i]));
            }
        
        if (no_op)
        {
            int num = stoi(s.substr(left, right-left));
            ans.push_back(num);
        }
        return ans;
    }
    
public:
    vector<int> diffWaysToCompute(string input) 
    {
        return solve(0, input.size(), input);
    }
};
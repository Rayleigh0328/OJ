class Solution {
private:
    int **f;
    set<int> val_pos;
    
    int solve(int start)
    {
        if (val_pos.find(start) == val_pos.end())
            return start + 1;
        int right_start = solve(start+1);
        return solve(right_start);
    }
    
public:
    bool isValidSerialization(string st) 
    {
        val_pos.clear();
        
        int n = 0;
        int pos = 0;
        while (pos < st.size())
        {
            if (st[pos] == ',') 
            {
                ++n;
                ++pos;
            }
            else
                if (st[pos] == '#')
                {
                    ++pos;
                }
                else
                {
                    val_pos.insert(n);
                    while (isdigit(st[pos])) ++pos;
                }
        }
        ++n;
        
        return (solve(0) == n);
    }
};
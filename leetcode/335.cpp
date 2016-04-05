class Solution {
public:
    bool isSelfCrossing(vector<int>& mv) 
    {
        if (mv.size() <= 3) return false;
        int i = 2;
        for (; i< mv.size() && mv[i] > mv[i-2]; ++i);
        
        if (i == mv.size()) return false;
        
        int limit_a;
        int limit_b;
        if (i == 2)
        {
            limit_a = mv[2];
            limit_b = mv[1];
        }
        else if (i == 3)
        {
            limit_a = mv[3];
            limit_b = (mv[3] == mv[1])?mv[2]-mv[0]:mv[2];
        }
        else if (mv[i] + mv[i-4] < mv[i-2])
        {
            limit_a = mv[i];
            limit_b = mv[i-1];
        }
        else
        {
            limit_a = mv[i];
            limit_b = mv[i-1] - mv[i-3];
        }
        
        int start = i;
        for (i++;i<mv.size();++i)
            if ((i-start) % 2 == 1)
            {
                if (mv[i] >= limit_b) return true;
                else limit_b = mv[i];
            }
            else
            {
                if (mv[i] >= limit_a) return true;
                else limit_a = mv[i];
            }
        return false;
    }
};
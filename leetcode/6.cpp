class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        if (numRows == 2)
        {
            string result = "";
            for (int i=0;i<s.size();i+=2) result += s[i];
            for (int i=1;i<s.size();i+=2) result += s[i];
            return result;
        }
        string *line = new string [numRows];
        
        int p = numRows * 2 - 2;
        for (int i=0;i<s.size();++i)
        {
            if (i % p < numRows) 
                line[i%p] += s[i];
            else
                line[p - i%p] += s[i];
        }
        string result = "";
        for (int i=0;i<numRows;++i) result += line[i];
        delete [] line;
        return result;
    }
};
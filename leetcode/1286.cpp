class CombinationIterator {
    
    string chars;
    vector<int> a;
    bool has_next;
public:
    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        a = vector<int>(combinationLength);
        for (int i=0;i<a.size();++i) a[i] = i;
        has_next = true;
    }
    
    string next() {
        string result;
        for (int i=0;i<a.size();++i)
            result.push_back(chars[a[i]]);
        
        int i;
        for (i=a.size()-1;i>=0;--i)
            if (a[i] + a.size() - i < chars.size()){
                ++a[i];
                for (int j=i+1;j<a.size();++j)
                    a[j] = a[j-1] + 1;
                break;
            }
        if (i == -1) has_next = false;
        return result;
    }
    
    bool hasNext() {
        return has_next;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

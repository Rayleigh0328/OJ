/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    
    unordered_map<int, int> match_pos;
    string s;

    void process_bracket(){
        stack<int> st;
        for (int i=0;i<s.size();++i)
            if (s[i] == '['){
                st.push(i);
            }
            else if (s[i] == ']'){
                match_pos.emplace(st.top(), i);
                st.pop();
            }
    }
    
    bool is_digit(char ch){
        if (ch == '-') return true;
        return '0' <= ch && ch <= '9';
    }
    
    NestedInteger parse(int left, int right){        
        // check if substring represent a number
        bool is_number = true;
        for (int i=left;i<right;++i)
            if (!is_digit(s[i])) is_number = false;
        if (is_number) return NestedInteger(stoi(s.substr(left, right-left)));
        
        NestedInteger result;
        if (s[left] == '['){
            ++left;
            --right;
        }
        int pos=left,next_pos;
        while (pos < right){
            next_pos = pos;
            while (next_pos < right && s[next_pos] != ',') 
                if (s[next_pos] == '[') 
                    next_pos = match_pos[next_pos] + 1;
                else 
                    ++next_pos;
            result.add(parse(pos, next_pos));
            pos = next_pos + 1;
        }
        return result;
    }
    
public:
    NestedInteger deserialize(string st) {
        s = st;
        process_bracket();
        return parse(0, s.length());
    }
};

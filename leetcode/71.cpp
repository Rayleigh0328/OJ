class Solution {
private:
    
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        while (!s.empty()) s.pop();
        
        int pos;
        while ((pos = path.find_first_of('/', 1)) != string::npos)
        {
            s.push(path.substr(1,pos-1));
            if (s.top().empty()) s.pop();
            path = path.substr(pos);
        }
        
        if  (path.size()>1) s.push(path.substr(1));
        
        // while (!s.empty())
        // {
        //     cout << s.top() << endl;
        //     s.pop();
        // }
        
        stack<string> rev;
        while(!rev.empty()) rev.pop();
        
        int cnt_par = 0;
        while (!s.empty())
        {
            if (s.top() == ".") 
            {
                s.pop();
            }
            else if (s.top() == "..")
            {
                s.pop();
                ++cnt_par;
            }
            else
            {
                if (cnt_par == 0) rev.push(s.top());
                else --cnt_par;
                s.pop();
            }
        }
        
        if (rev.empty()) return "/";
        
        string ans = "";
        while (!rev.empty())
        {
            ans += '/' + rev.top();
            rev.pop();
        }
        return ans;
    }
};
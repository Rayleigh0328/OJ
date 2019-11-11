// construct the tree
// traverse the tree to get longest file path

struct Node{
    string name;
    vector<Node*> next;
    
    Node(const string &data){
        name = data;
    }
};

class Solution {
    int ans;
    
    bool is_file(const string& name){
        if (name.find(".") != string::npos) return true;
        return false;
    }
    
    void dfs(Node* p, int current_length){
        if (is_file(p->name))
            ans = max(ans, static_cast<int>(current_length + p->name.length()));
        else {
            for (Node* q : p->next)
                dfs(q, current_length + p->name.length() + 1);
        }
    }
    
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string line;
        Node* root = new Node("/");
        stack<Node*> st;
        st.push(root);
        while (getline(ss,line)){
            int count_tab = 0;
            while (line[count_tab] == '\t') ++count_tab;
            // cout << line << ": " << count_tab << " after trim:" << line.substr(count_tab)<< endl;
            while (count_tab + 1 < st.size()) st.pop();
            Node* q = new Node(line.substr(count_tab));
            st.top()->next.push_back(q);
            st.push(q);
        }
        ans = 0;
        dfs(root, 0);
        return max(0, ans-2);
    }
};

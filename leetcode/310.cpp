class Solution {
private:
    struct node
    {
        int data;
        node* next;
    };
    
    void insert_edge(int x, int y, node** g)
    {
        node *tmp = new node;
        tmp->data = y;
        tmp->next = NULL;
        if (g[x] == NULL) g[x] = tmp;
        else
        {
            tmp->next = g[x];
            g[x] = tmp;
        }
    }
    
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& e) 
    {
        node** g = new node *[n];
        for (int i=0;i<n;++i) g[i] = NULL;
        
        int * deg = new int [n];
        for (int i=0;i<n;++i) deg[i] = 0;
        
        for (int i=0; i<e.size(); ++i)
        {
            insert_edge(e[i].first, e[i].second, g);
            insert_edge(e[i].second, e[i].first, g);
            ++deg[e[i].first];
            ++deg[e[i].second];
        }
        
        bool *flag = new bool [n];
        for (int i=0;i<n;++i) flag[i] =false;
        
        int *depth = new int [n];
        for (int i=0;i<n;++i) depth[i] = 0;
        
        queue<int> que;
        while (!que.empty()) que.pop();
        
        for (int i=0;i<n;++i)
            if (deg[i] == 1)
            {
                flag[i] = true;
                depth[i] = 0;
                que.push(i);
            }
        
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            node *q = g[cur];
            while (q!=NULL)
            {
                if (!flag[q->data])
                    if (--deg[q->data] == 1)
                    {
                        flag[q->data] = true;
                        depth[q->data] = depth[cur] + 1;
                        que.push(q->data);
                    }
                q = q->next;
            }
        }
        
        int max_depth = 0;
        for (int i=0;i<n;++i)
            max_depth = max(max_depth, depth[i]);
        
        vector<int> ans;
        ans.clear();
        for (int i=0;i<n;++i)
            if (depth[i] == max_depth)
                ans.push_back(i);
                
        return ans;
    }
};
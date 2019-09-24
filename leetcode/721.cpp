class DisjointSet{
private:
    int n;
    vector<int> leader;
    vector<int> weight;

public:
    DisjointSet(int size):
        n(size)
    {
        leader = vector<int>(n);
        weight = vector<int>(n);
        for (int i=0;i<n;++i) {
            leader[i] = i;
            weight[i] = 1;
        }
    }

    int find_set(int k){
        if (leader[k] == k) return k;
        leader[k] = find_set(leader[k]);
        weight[k] = weight[leader[k]];
        return leader[k];
    }

    void union_set(int x, int y){
        if (find_set(x) == find_set(y)) return;
        // always attach smaller weight to larger weight
        // make sure the set of x have larger weight
        if (weight[find_set(x)] < weight[find_set(y)]){
            union_set(y,x);
        }
        else{
            weight[find_set(x)] = weight[find_set(x)] + weight[find_set(y)];
            leader[find_set(y)] = find_set(x);
        }
    }

    int count_set(){
        unordered_set<int> label_set;
        for (int i=0;i<n;++i)
            label_set.insert(find_set(i));
        return label_set.size();
    }

    int get_weight(int k){
        return weight[find_set(k)];
    }

    void print_leader(){
        for (int i=0;i<n;++i){
            printf("%d --> %d\n", i, find_set(i));
        }
    }
};


class Solution {
    bool overlap(const unordered_set<string> &x, const unordered_set<string> &y){
        for (auto element : x)
            if (y.find(element) != y.end()) return true;
        return false;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<string> account_name(n);
        vector<unordered_set<string>> account_email_set(n);
        
        for (int i=0;i<n;++i){
            account_name[i] = accounts[i][0];
            for (int j=1; j<accounts[i].size();++j)
                account_email_set[i].insert(accounts[i][j]);
        }
        
        DisjointSet ds(n);
        for (int i=0; i<n; ++i)
            for (int j=i+1;j<n;++j)
                if (account_name[i] == account_name[j] && overlap(account_email_set[i], account_email_set[j]))
                    ds.union_set(i,j);
        
        vector<vector<string>> result;
        unordered_set<int> processed;
        for (int i=0;i<n;++i){
            int label = ds.find_set(i);
            if (processed.find(label) == processed.end()){
                processed.emplace(label);
                vector<string> account;
                account.push_back(account_name[label]);
                set<string> email_set;
                for (int j=i; j<n;++j)
                    if (ds.find_set(j) == label){
                        for (string email : account_email_set[j]) email_set.insert(email);
                    }
                for (string email : email_set)
                    account.push_back(email);
                result.push_back(account);
            }
        }
        return result;
    }
};

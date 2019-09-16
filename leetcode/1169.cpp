class Solution {
    vector<string> name;
    vector<int> ti;
    vector<int> amt;
    vector<string> city;

    int my_abs(int x){
        if (x < 0) return -x;
        return x;
    }

    bool conflict(int x, int y){
        if (name[x].compare(name[y]) == 0
                && city[x].compare(city[y]) != 0
                && my_abs(ti[x] - ti[y]) <=60 ) return true;
        return false;
    }

public:

    vector<string> invalidTransactions(vector<string>& transactions) {
        // process transactions to get 4 arrays
        // name, t, amount, city
        for (auto trans : transactions){
            string n;
            int t, a;
            string tmp = trans;
         
            int pos = tmp.find(','); 
            name.push_back(tmp.substr(0,pos));
            tmp = tmp.substr(pos+1);
            
            pos = tmp.find(',');
            ti.push_back(stoi(tmp.substr(0,pos)));
            tmp = tmp.substr(pos+1);

            pos = tmp.find(',');
            amt.push_back(stoi(tmp.substr(0,pos)));
            tmp = tmp.substr(pos+1);

            city.push_back(tmp);
        }
//        cout << "name: ";for (auto tmp : name)  cout << tmp << " "; cout << endl; 
//        cout << "time: ";for (auto tmp : ti) cout << tmp << " "; cout << endl; 
//        cout << "amount: ";for (auto tmp : amt) cout << tmp << " "; cout << endl; 
//        cout << "city: ";for (auto tmp : city) cout << tmp << " "; cout << endl; 
        // populate valid
        vector<bool> valid(transactions.size(), true);
        for (int i=0;i<transactions.size();++i){
            if (amt[i] > 1000) valid[i] = false;
            for(int j=i+1; j<transactions.size();++j){
                if (conflict(i,j)){
                    valid[i] = false;
                    valid[j] = false;
                }
            }
        }
        // populate result based on valid
        vector<string>ans;
        for (int i=0;i<transactions.size();++i)
            if (!valid[i]) ans.push_back(transactions[i]);
        return ans;
    }
};


template<typename T>
void get_most_frequent_element(const vector<T>& u, T &element, int &freq){
    if (u.empty()) {freq = -1; return;}
    vector<T> v(u);
    vector<int> f(v.size(),0);
    sort(v.begin(), v.end());
    f[0] = 1;
    for (int i=1; i<v.size();++i)
        if (v[i] == v[i-1]) f[i] = f[i-1] + 1;
        else f[i] = 1;
    int max_pos = 0;
    for (int i=1; i<f.size();++i)
        if (f[i] > f[max_pos]) max_pos = i;
    element = v[max_pos];
    freq = f[max_pos];
}


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& v) {
        vector<int> result;
        int majority;
        int freq;
        get_most_frequent_element(v, majority, freq);
        cout << majority << " " << freq << endl;
        if (freq >= (v.size()+1)/2){
            cout << "has majority: "<< majority << endl;
            for (int i=0;i<v.size();++i)
                if (v[i] != majority) {
                    result.push_back(majority);
                    result.push_back(v[i]);
                }
            if (v.size() % 2 == 1) result.push_back(majority);
        }
        else{
            cout << "no majority" << endl;
            sort(v.begin(), v.end());
            int mid = v.size() / 2;
            for (int i=0; i<mid; ++i){
                result.push_back(v[i]);
                result.push_back(v[mid+i]);
            }
            if (v.size() % 2 == 1) result.push_back(v[v.size()-1]);
        }
        return result;
    }
};


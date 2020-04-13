class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> a(m);
        for (int i=0;i<m;++i) a[i] = i+1;
        
        vector<int> result;
        for (auto data:queries){
            // find pos
            int pos = 0;
            for (int i=0;i<a.size();++i)
                if (a[i] == data) {
                    pos = i;
                    break;
                }
            // printf("pos: %d\n", pos);
            result.push_back(pos);
            // move
            int tmp = a[pos];
            for (int i=pos-1;i>=0;--i) a[i+1] = a[i];
            a[0] = tmp;
        }
        return result;
    }
};

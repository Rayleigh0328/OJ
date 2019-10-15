class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        const int inf = (1<<25);
        vector<int> s;
        for (auto e : a){
            bool exist = true;
            while (!s.empty() && s.back()>0 && e <0){
                int t = s.back();
                if (t > -e) {
                    exist = false;
                    break;
                }
                else if (t == -e) {
                    s.pop_back();
                    exist = false;
                    break;
                }
                else {
                    s.pop_back();
                }
            }
            if (exist) s.push_back(e);
        }
        return s;
    }
};

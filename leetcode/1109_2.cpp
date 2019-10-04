class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> add(n+1,0);
        for (auto e : bookings){
            add[e[0]-1] += e[2];
            add[e[1]] += -e[2];
        }
        int sum = 0;
        vector<int> ans;
        for (int i=0;i<n;++i){
            sum += add[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

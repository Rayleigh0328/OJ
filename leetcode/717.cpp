class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        queue<int> q;
        for (auto x:bits) q.push(x);
        bool last_one_bit;
        while (q.size()>0){
            if (q.front() == 0){
                q.pop();
                last_one_bit = true;
            }
            else{
                q.pop();
                q.pop();
                last_one_bit = false;
            }
        }
        return last_one_bit;
    }
};

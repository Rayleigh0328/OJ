typedef pair<int, int> QueueElement;

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) { 
        // special cases
        if (a.empty()) return -1;
        if (k <=0 ){
            for (auto x : a) if (x >= k) return 1; 
            return -1;
        }
        
        int ans = a.size() + 1;
        deque<QueueElement> q; 
        int total_score = 0;
        int total_length = 0;
        for (auto x : a){
            total_score += x;
            total_length += 1;
            QueueElement element(x, 1);
            while (!q.empty() && element.first <=0){
                QueueElement tmp = q.back();
                q.pop_back();
                element.first += tmp.first;
                element.second += tmp.second;
            }

            if (element.first <=0) {
                q.clear();
                total_score = total_length = 0;
            }
            else {
                q.push_back(element);
            }

            while (total_score >= k){
                ans = min(ans, total_length);
                total_score -= q.front().first;
                total_length -= q.front().second;
                q.pop_front();
            }    
        }
        
        if (ans == a.size() + 1) return -1;
        return ans;
    }
};

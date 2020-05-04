class Solution {
    typedef pair<int,int> MyType;
public:
    int longestSubarray(vector<int>& a, int limit) {
        deque<MyType> max_que;
        deque<MyType> min_que;

        int result = 0;
        int prev = 0;
        
        for (int i=0;i<a.size();++i){
            
            while (!max_que.empty() && max_que.back().first < a[i]) max_que.pop_back();
            max_que.push_back(MyType(a[i],i));
            
            while (!min_que.empty() && min_que.back().first > a[i]) min_que.pop_back();
            min_que.push_back(MyType(a[i],i));
            
            while (max_que.front().first - min_que.front().first > limit){
                if (max_que.front().second == min_que.front().second) {
                    prev = max_que.front().second + 1;
                    max_que.pop_front();
                    min_que.pop_front();
                }
                else if (max_que.front().second < min_que.front().second) {
                    prev=max_que.front().second + 1;
                    max_que.pop_front();
                }
                else {
                    prev=min_que.front().second + 1;
                    min_que.pop_front();
                }
            }
            
            result = max(result, i - prev + 1);
        }
        
        return result;
    }
};

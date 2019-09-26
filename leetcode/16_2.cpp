class Solution {
    int K;

    void update_ans(int& ans, int& diff, int current){
        // printf("update with value %d\n", current);
        if (abs(current - K) < diff){
            diff = abs(current - K);
            ans = current;
        }
    }

public:
    int threeSumClosest(vector<int>& a, int target) {
        // for each a[i] a[j], try to find target-a[i]-a[j]

        // construct map to count a value and its frequence
        // rev_count is constructed so that is is possible
        // to use upper_bound to get smaller element
        K = target;
        map<int, int> count;
        map<int, int, std::greater<int>> rev_count;
        for (int i=0;i<a.size();++i)
            if (count.find(a[i]) == count.end()) {
                count.emplace(a[i], 1);
                rev_count.emplace(a[i],1);
            }
            else {
                ++count[a[i]];
                ++rev_count[a[i]];
            }
        // for (auto x : count)
        //    printf("%d --> %d\n", x.first, x.second); 

        int diff = (1<<30), ans;
        int value1, value2, value3, freq1, freq2, freq3;
        for (auto it1=count.begin(); it1!=count.end(); ++it1 ){
            value1 = it1->first;
            freq1 = it1->second;
            // printf("try value1 %d, freq1 %d\n", value1, freq1);
            if (freq1 >= 3) update_ans(ans, diff, 3*value1);
            auto it2 = it1;
            for (++it2; it2 != count.end(); ++it2){
                value2 = it2->first;
                freq2 = it2->second;
                // printf("\ttry value2 %d, freq2 %d\n", value2, freq2);
                if (freq1 >=2) update_ans(ans, diff, value1 * 2 + value2);
                if (freq2 >=2) update_ans(ans, diff, value1 + value2 * 2);
                
                int goal = target - value1 - value2;
                // printf("\tgoal: %d\n", goal);
                auto it3 = count.find(goal);
                if (it3!=count.end() && it3->first != value1 && it3->first != value2) return target;
                it3 = count.upper_bound(goal);
                if (it3!=count.end() && it3->first != value1 && it3->first != value2) update_ans(ans, diff, value1 + value2 + it3->first);
                it3 = rev_count.upper_bound(goal);
                if (it3!=rev_count.end() && it3->first != value1 && it3->first != value2) update_ans(ans, diff, value1 + value2 + it3->first);
                // printf("\tcurrent diff: %d\n", diff);
                // printf("\tcurrent ans: %d\n", ans);
            }
            // printf("current diff: %d\n", diff);
            // printf("current ans: %d\n\n", ans);
        }
        return ans;
    }
};


class Solution {
    const int inf = (1<<25);
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // create a map from skill to index
        int total_skill = req_skills.size();
        unordered_map<string,int> skill_to_index;
        for (int i=0;i<total_skill;++i)
            skill_to_index[ req_skills[i] ] = i;

        // convert people's skills set into a int
        int total_emp = people.size();
        vector<int> emp(total_emp, 0);
        for (int i=0;i<total_emp;++i){
            for (string skill : people[i])
                emp[i] += (1 << skill_to_index[skill]);
        }

        // initial state 0
        // target state (1<<total_skill) - 1;
        int target = (1<<total_skill) - 1;
        vector<int> f(target+1, inf);
        vector<int> prev(target+1, 0);
        vector<int> record(target+1, 0);
        f[0] = 0;
        prev[0] = record[0] = -1;

        for (int i=0, next_s;i<total_emp;++i){
            for (int s = 0; s <= target; ++s){
                next_s = (s | emp[i]);
                if (f[next_s] > f[s] + 1){
                    f[next_s] = f[s] + 1;
                    prev[next_s] = s;
                    record[next_s] = i;
                }
            }
        }

        // reconstruct answer
        int current_s = target;
        vector<int> ans;
        while (current_s > 0){
            ans.push_back(record[current_s]);
            current_s = prev[current_s];
        }
        return ans;
    }
};


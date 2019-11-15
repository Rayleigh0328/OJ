class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {0};
        
        unordered_map<char, int> char_to_last_pos;
        for (int i=0;i<S.length();++i)
            char_to_last_pos[S[i]] = i;
        vector<int> ans;
        int left = 0, right;
        while (left < S.length()){
            right = left + 1;
            for (int i=left;i<right;++i)
                right = max(right, char_to_last_pos[S[i]]+1);
            // printf("left %d, right %d\n", left, right);
            ans.push_back(right-left);
            left = right;
        }
        
        return ans;
    }
};

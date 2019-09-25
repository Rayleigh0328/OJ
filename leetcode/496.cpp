template<typename T>
bool compare_larger_or_equal(T x, T y){
    return x >= y;
}

template<typename T>
std::vector<int>& find_next_element(
        const std::vector<T> &v,
        int start_index,
        int end_index,
        int increment_amount,
        bool (*cmp)(T, T)
    )
{
    std::vector<int> &result = *(new std::vector<int>(v.size()));
    std::stack<int> s;
    for (int i=start_index; i != end_index; i+= increment_amount){
        while ( !s.empty() && cmp(v[i], v[s.top()]) ) 
            s.pop();
        if (s.empty()) 
            result[i] = -1;
        else
            result[i] = s.top();
        s.push(i);
    }

    return result;
}

template<typename T>
std::vector<int>& nearest_g_on_right(const std::vector<T> &v){
    return find_next_element(v, v.size() - 1, -1, -1, compare_larger_or_equal);
}


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> &next = nearest_g_on_right(nums2);
        unordered_map<int,int> value_pos;
        for (int i=0;i<nums2.size();++i) value_pos.emplace(nums2[i], i);
        vector<int> ans;
        int p;
        for (auto x : nums1){
            int tmp = next[value_pos[x]];
            ans.push_back(tmp == -1 ? -1 : nums2[tmp]);
        }
        return ans;
    }
};

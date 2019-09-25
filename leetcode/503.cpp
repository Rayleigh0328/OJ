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
    vector<int> nextGreaterElements(vector<int>& nums) {
        // doubling nums
        vector<int> doubled(2*nums.size());
        for(int i=0;i<nums.size();++i) doubled[i] = doubled[nums.size()+i] = nums[i];
        // calcualte greater position on right
        vector<int> next_pos = nearest_g_on_right(doubled);
        vector<int> ans(nums.size());
        for (int i=0;i<nums.size();++i)
            if (next_pos[i] == -1) ans[i] = -1;
            else ans[i] = doubled[next_pos[i]];
        return ans;
    }
};

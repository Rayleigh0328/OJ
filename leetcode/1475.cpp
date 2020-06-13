template<typename T>
bool compare_smaller(T x, T y){
    return x < y;
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
std::vector<int>& nearest_leq_on_right(const std::vector<T> &v){
    return find_next_element(v, v.size() - 1, -1, -1, compare_smaller);
}

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> index = nearest_leq_on_right(prices);
        vector<int> result(n);
        for (int i=0;i<n;++i)
            if (index[i] == -1) result[i] = prices[i];
            else result[i] = prices[i] - prices[index[i]];
        return result;
    }
};

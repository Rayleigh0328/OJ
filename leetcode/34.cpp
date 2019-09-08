template<typename T>
int binary_search(
        const std::vector<T>& vec, 
        int start, 
        int end, 
        const T& key,
        bool lower_bound)
{
    // end condition
    if(start >= end) return (lower_bound?vec.size():-1); 

    // mid
    int middle = start + ((end - start) / 2);
    // std::cout << start << " " << end <<" " << middle << std::endl;

    if(vec[middle] == key) { 
        if (lower_bound)  
            return min(middle, binary_search(vec, start, middle, key, lower_bound));
        else
            return max(middle, binary_search(vec, middle + 1, end, key, lower_bound));
    }
    else if(vec[middle] > key) {
        return binary_search(vec, start, middle, key, lower_bound);
    }
    else {
        return binary_search(vec, middle + 1, end, key, lower_bound);
    }
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = binary_search(nums, 0, (int)nums.size(), target, true);
        
        vector<int> result;
        if (lb < nums.size()){
            result.push_back(lb);
            result.push_back(binary_search(nums,0,nums.size(),target,false));
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
    
};




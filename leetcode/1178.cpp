template<typename T>
int binary_search_mono_inc_eq(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] == key ? start : -1);
         
        mid = (start + end) / 2;
        if (v[mid] == key) return mid;
        if (v[mid] < key) start = mid + 1;
        else end = mid; 
    }
    return -1;
}
// search 2 in [1,2,2,2,3] will give 1
template<typename T>
int binary_search_mono_inc_less_than(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] < key ? start : -1);
        if (start == end - 2) {
            if (v[start+1] < key) return start + 1;
            else if (v[start] < key) return start;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] < key) start = mid;
        else end = mid; 
    }
    return -1;
}

// search 2 in [1,2,2,2,3] will give rightmost 2 
template<typename T>
int binary_search_mono_inc_leq(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] <= key ? start : -1);
        if (start == end - 2) {
            if (v[start+1] <= key) return start + 1;
            else if (v[start] <= key) return start;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] <= key) start = mid;
        else end = mid; 
    }
    return -1;
}

// search 2 in [1,2,2,2,3] will give 3
template<typename T>
int binary_search_mono_inc_greater_than(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] > key ? start : -1);
        if (start == end - 2) {
            if (v[start] > key) return start;
            else if (v[start + 1] > key) return start + 1;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] > key) end = mid + 1;
        else start = mid + 1; 
    }
    return -1;
}

// search 2 in [1,2,2,2,3] will give left most 2
template<typename T>
int binary_search_mono_inc_geq(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] >= key ? start : -1);
        if (start == end - 2) {
            if (v[start] >= key) return start;
            else if (v[start + 1] >= key) return start + 1;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] >= key) end = mid + 1;
        else start = mid + 1; 
    }
    return -1;
}

int get_finger_print(string st){
	int ans = 0;
	for (int i=0; i<st.size(); ++i)
		ans = (ans | (1 << (st[i] - 'a')));
	return ans;
}


int solve(string st, const vector<int> &v, int left, int right){
	int fp_st = get_finger_print(st);
	int fp_first = get_finger_print(st.substr(0,1));
	int ans = 0;
	for (int i=left; i<right; ++i)
		if ((v[i] & fp_first) && ((v[i] | fp_st) == fp_st)) ++ans;
	return ans;
}


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> fps;
        for (auto word : words) fps.push_back(get_finger_print(word));
        sort(fps.begin(), fps.end());
//        for (auto x : fps) cout << x << " "; cout << endl;
        vector<int> ans;
        for (auto puzzle : puzzles){
        	int fp = get_finger_print(puzzle);
            int fp_first = get_finger_print(puzzle.substr(0,1));
        	int left = binary_search_mono_inc_geq(fps, 0, fps.size(), fp_first);
        	int right = binary_search_mono_inc_leq(fps, 0, fps.size(), fp);
//            cout << fp << " " << left << " " << right << endl;
            if (left == -1) left = 0;
            if (right == -1) right = fps.size()-1;
        	ans.push_back(solve(puzzle, fps,left, right+1));
        }
        return ans;
    }
};

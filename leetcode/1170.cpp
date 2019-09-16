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


class Solution {
public:

	int f(string st){
		vector<int> v(256,0);
		for (int i=0;i<st.length();++i) ++v[st[i]];
		for (auto x : v) if (x > 0) return x;
        return 0;
	}

	int solve(string st, const vector<int> &v){
		int pos = binary_search_mono_inc_greater_than(v,0,v.size(),f(st));
		if (pos == -1) return 0;
		return v.size() - pos;
	}

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> words_f(words.size());
        for (int i=0;i<words_f.size(); ++i) words_f[i] = f(words[i]);
        sort(words_f.begin(), words_f.end());
    	vector<int> ans;
    	for (auto query : queries){
    		ans.push_back(solve(query, words_f));
    	}
        return ans;
    }
};

#include<vector>
#include<string>
#include<iostream>

using namespace std;
template<typename T>
std::vector<T>& find_max_sub_array_sum(
        const std::vector<T>&v,
        int start_index, 
        int end_index,
        int increment_amount
    )
{
    std::vector<T>& result = *(new std::vector<T>(v.size()));
    if (start_index == end_index) return result;
    result[start_index] = v[start_index];
    for (int i = start_index + increment_amount; i != end_index; i+= increment_amount)
        result[i] = std::max(v[i], result[i - increment_amount] + v[i]);
    return result;
}

template<typename T>
std::vector<T>& max_sub_array_sum_on_left(const std::vector<T> &v){
    return find_max_sub_array_sum(v, 0, v.size(), 1);
}

template<typename T>
T get_max_element(const std::vector<T>&v){
    if (v.empty()) return -1;
    
    T result = v[0];
    for (auto x : v)
    	if (x > result) result = x;
    return result;
}

long long max(long long x, long long y){
    if ( x > y) return x;
    return y;
}

void print_vector(const vector<int>& v){
    for (auto x : v) cout << x  << " ";
    cout << endl;
}


class Solution {
public:
	int module = 1000000007;

    int kConcatenationMaxSum(vector<int>& a, int k) {
        if (a.size() == 0) return 0;
        vector<int> &f = max_sub_array_sum_on_left(a);
        if (k == 1) return get_max_element(f);
        
//        cout <<"f: " << endl; print_vector(f);

        vector<int> left(a.size());
        left[0] = a[0];
        for (int i=1;i<a.size();++i) left[i] = a[i] + left[i-1];
//        cout <<"left: " << endl; print_vector(left);
        
        vector<int> right(a.size());
    	right[a.size()-1]=a[a.size()-1];
    	for (int i=a.size()-2;i>=0;--i) right[i] = a[i] + right[i+1];
//        cout <<"right: " << endl; print_vector(right);

    	long long total_sum = left[a.size()-1];
    	long long ans = 0l;
//        cout << "total_sum: "<<total_sum << endl;
//        cout << "max_f: "<<get_max_element(f)<< endl;
//        cout << "max_left: "<<get_max_element(left)<< endl;
//        cout << "max_right: "<<get_max_element(right)<< endl;
    	if (total_sum > 0){
    		ans = max(
    				get_max_element(f),
    				get_max_element(left) + get_max_element(right) + total_sum * (k-2)
    			); 
    	}
    	else {
    		ans = max(
    				get_max_element(f),
    				get_max_element(left) + get_max_element(right)
    			);
    	}
        if (ans < 0) ans = 0;
    	return ans % module;
    }
};

class Solution {
    vector<int> start;
    vector<int> end;
    
    int get_len(int k){
        return end[k] - start[k] + 1;
    }
    
    bool connectable(int x, int y){
        return end[x]+2 == start[y];
    }
public:
    int maxRepOpt1(string st) {
        
        int pos;
        int result = 0;
        for (char ch='a'; ch <='z'; ++ch){
            start.clear();
            end.clear();
            for (pos = 0; pos < st.length(); ++pos){
                if (st[pos]==ch) {
                    if (end.empty() || end[end.size()-1]!=pos-1){
                        start.push_back(pos);
                        end.push_back(pos);
                    }
                    else {
                        ++end[end.size()-1];
                    }
                }
            }
            
            // printf("for char %c:\n", ch);
            // for (int i=0;i<start.size();++i){
            //     printf("[%d, %d]\n", start[i], end[i]);
            // }
            
            if (start.size() == 0) continue;
            if (start.size() == 1){
                // case 1: only 1 substring
                result = max(result, get_len(0));
            }
            else if (start.size() == 2){
                // case 2: only 2 substring
                // case 2.1 distance of two substring is 1
                if (connectable(0,1)){
                    result = max(result, get_len(0) + get_len(1));
                }
                else{
                // case 2.2 distance of two substring is more than 2
                    result = max(result, 1 + max(get_len(0), get_len(1)));
                }
            }
            else {
                result = max(result, get_len(0) + 1);
                for (int i=1; i<start.size();++i)
                    if (connectable(i-1, i)){
                        result = max(result, 1+get_len(i-1)+ get_len(i));
                    }
                    else {
                        result = max(result, get_len(i) + 1);
                    }
            }
            
        }
        return result;
    }
};

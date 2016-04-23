class Solution {
private:
	typedef unordered_map<string, int> string_map;
	string_map ori_map;
	string_map rev_map;
	vector<vector<int>> ans;
	set<int> check_rep;
	int tot;

	set<int> manacher(string s)
    {
        int len = s.length()*2+3;
        int *a = new int [len];
        a[0] = 257;
        for (int i=0;i<s.length();++i)
        {
            a[i*2+1] = 256;
            a[i*2+2] = s[i];
        }
        a[len-2] = 256;
        a[len-1] = 258;
        
        //right keep track on the right most palindrome boundary
        //mid keep track on corresponding mid point
        int right = 0;
        int mid = 0;
        int *p = new int [len];
        for (int i=0;i<len;++i) p[i] = 1;
        for (int i=1;i<len-1;++i)
        {
            if (i < right) 
                p[i] = min(p[2*mid - i], right - i);
            while (a[i+p[i]] == a[i-p[i]]) ++p[i];
            if (i+p[i] > right)
            {
                right = i+p[i];
                mid = i;
            }
        }
        
        set<int> ans;
        ans.clear();
        for (int i=0;i<len;++i)
            if (i+p[i] == len-1) ans.insert(p[i]-1);
        delete [] a;
        return ans;
    }

    void update_ans(int x, int y)
    {
    	if (x == y) return;
    	int code = x*tot + y;
    	if (check_rep.find(code) == check_rep.end())
    	{
    	    check_rep.insert(code);
    	    vector<int> tmp;
    	    tmp.clear();
    	    tmp.push_back(x);
    	    tmp.push_back(y);
    	    ans.push_back(tmp);
    	}
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {   
    	ans.clear();
    	check_rep.clear();
    	tot = words.size();
    	
    	ori_map.clear();
    	for (int i=0;i<words.size();++i)
    		ori_map.emplace(words[i], i);

    	vector<string> rev(words);
    	rev_map.clear();
    	for (int i=0;i<rev.size();++i)
    	{
    		reverse(rev[i].begin(), rev[i].end());
    		rev_map.emplace(rev[i],i); 
    	}
    	
    	set<int> pal_set;
    	string tmp;
    	
    	for (int i=0;i<words.size();++i)
    	{
    	    pal_set.clear();
    	    pal_set = manacher(words[i]);
    	    
    // 	    printf("Word %d palindrome suffix: ",i);
    // 		for (set<int>::iterator it = pal_set.begin(); it != pal_set.end(); ++it) 
    // 			printf("%d ", *it);
    // 		printf("\n");
    		
    	    const string &cur = words[i];
    	    tmp = "";
    	    for (int j=0;j<cur.length();tmp+=cur[j++])
    	    {
    	        if (pal_set.find(cur.length()-j) != pal_set.end() && rev_map.find(tmp) != rev_map.end())
    	            update_ans(i, rev_map[tmp]);
    	    }
    	    if (rev_map.find(tmp) != rev_map.end()) update_ans(i, rev_map[tmp]);
    	}
        
        
        for (int i=0;i<words.size();++i)
        {
            pal_set = manacher(rev[i]);
            
    //         printf("Word %d palindrome prefix: ",i);
    // 		for (set<int>::iterator it = pal_set.begin(); it != pal_set.end(); ++it) 
    // 			printf("%d ", *it);
    // 		printf("\n");
    		
            const string &cur = words[i];
            tmp = "";
            for  (int j=cur.length(); j>0; tmp+=cur[--j])
            {
                // cout << j<< ":" << tmp << endl;
                if (pal_set.find(j) != pal_set.end() && ori_map.find(tmp) != ori_map.end())
                    update_ans(ori_map[tmp], i);
            }
            if (ori_map.find(tmp) != ori_map.end()) update_ans(ori_map[tmp],i);
        }
    	return ans;
    }
};

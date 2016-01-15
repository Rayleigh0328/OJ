class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher's ALGORITHM
        //create new string
        //add two special symbol at the beginning and the end.
        //and third special symbol between each char in s
        //aba ==> $#a#b#a#@
        
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
        
        int max_pos = 0;
        for (int i=0;i<len;++i)
            if (p[i] > p[max_pos])
                max_pos = i;
                
        string result = "";
        for (int i=max_pos - p[max_pos] + 1; i<max_pos+p[max_pos];++i)
            if (a[i]<256) result += a[i];
    
        delete a;
        delete p;
        return result;
    }
};
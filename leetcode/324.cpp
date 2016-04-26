class Solution {
private:
    void find_kth(vector<int>& a, int left, int right, int k)
    {
        int pivot = a[right];
        int pos = left;
        for (int i=left;i<right;++i)
            if (a[i] < a[right])
                swap(a[i], a[pos++]);
        swap(a[pos],a[right]);
        if (k == pos) return;
        if (pos < k) find_kth(a, pos+1, right, k);
        if (pos > k) find_kth(a, left, pos-1, k);
    }
    
public:
    void wiggleSort(vector<int>& a) 
    {
        if (a.size()<2) return ;
        
        // deal with odd length
        int len = a.size();
        if (len % 2 == 1)
        {
            int min_pos = 0;
            for (int i=1;i<len;++i)
                if (a[i] < a[min_pos]) min_pos = i;
            swap(a[min_pos], a[--len]);
        }
        
        int k = len/2 - 1;
        
        find_kth(a, 0, len-1, k);
        // a[k] will be the kth number in a
        // a[0]..a[k-1] are all leq a[k]
        // a[k+1]..a[len-1] are all geq a[k]
        
        // cout << k << endl;
        // for (int i=0;i<a.size();++i)
        //     cout << a[i] << " ";
        // cout << endl;
        
        int special = a[k];
        // cout << "special: " << special << endl;
        
        for (int i=1;i<=k;i+=2)
            swap(a[i],a[k+1+i]);
        
        for (int i=1;i<len;i+=2)
            if (a[i-1] > a[i]) swap(a[i-1],a[i]);

        // cout << "Make paris" << endl;
        // for (int i=0;i<a.size();++i)
        //     cout << a[i] << " ";
        // cout << endl;

        int p1 = 0, p2 = 0;
        for (;p2<len;p2+=2)
            if (a[p2] == a[p2+1])
            {
                while (p1<len && (a[p1]==special ||a[p1+1] == special)) p1+=2;
                swap(a[p1],a[p2]);
            }
        
        // cout << "Solve conflicts within a pair" << endl;
        // for (int i=0;i<a.size();++i)
        //     cout << a[i] << " ";
        // cout << endl;
       
        p1 = 0;
        for (p2=0;p2<len;p2+=2)
            if (a[p2] == special)
            {
                while (p1<len && a[p1] == special) p1 += 2;
                if (p1 >= p2) continue;
                swap(a[p1],a[p2]);
                swap(a[p1+1],a[p2+1]);
            }
        
        // cout << "Solve conflicts between pairs" << endl;
        // for (int i=0;i<a.size();++i)
        //     cout << a[i] << " ";
        // cout << endl;
    }
};
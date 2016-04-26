class Solution {
private:
    void find_prime(int k, vector<int> &p)
    {
        //printf("k: %d\n",k);

        bool *a = new bool [k+1];
        for (int i=0;i<k+1;++i) a[i] = true;
        a[0] = a[1] = false;
        for (int i=2;i<=k;++i)
            if (a[i])
            {
                p.push_back(i);
                for (int j=2*i; j<=k; j+=i)
                    a[j] = false;
            }
    }

    int solve(int n, int k, const vector<int>& sq)
    {
        // printf("n:%d k:%d\n", n,k);
        if (k == -1) return 1;
        return solve(n, k-1,sq) + ((n>=sq[k])?solve(n/sq[k],k,sq):0);
    }
public:
    int bulbSwitch(int n) 
    {
        if (n == 0) return 0;
        vector<int> sq;
        find_prime(int(sqrt(INT_MAX))+1,sq);
        
        //printf("Number of primes: %d\n", int(sq.size()));
        //printf("Largest prime: %d\n", sq[sq.size()-1]);
        
        for (int i=0;i<sq.size();++i)
            sq[i] = sq[i] * sq[i];
            
        //cout << sq.size() << endl;
        //for (int i=0;i<sq.size();++i)    
        //    cout << sq[i] << " ";
        //cout << endl;
        
        for (int i=0;i<sq.size();++i)
            if (sq[i] > n) return solve(n,i-1,sq);
        
        //cout << "HERE" << endl;
        return solve(n, sq.size() -1, sq);
    }
};
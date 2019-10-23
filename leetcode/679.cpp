class Solution {
    
    double calculate(int op, double a, double b){
        if (op == 0) return a + b;
        if (op == 1) return a - b;
        if (op == 2) return a * b;
        return a / b;
    }
    
    bool solve(const vector<int> &a, int op1, int op2, int op3){
        double result = calculate(op1, a[0],a[1]);
        result = calculate(op2,result,a[2]);
        result = calculate(op3, result, a[3]);
        if (abs(result - 24) < 1e-8) return true;
        
        double result1 = calculate(op1, a[0],a[1]);
        double result2 = calculate(op2, a[2],a[3]);
        result = calculate(op3, result1, result2);
        if (abs(result - 24) < 1e-8) return true;
        
        result = calculate(op1, a[2], a[3]);
        result = calculate(op2, a[1], result);
        result = calculate(op3, a[0], result);
        if (abs(result - 24) < 1e-8) return true;
        return false;
    }
    
public:
    bool judgePoint24(vector<int>& a) {
        sort(a.begin(),a.end());
        do{
            // for (auto x : a) cout << x << " "; cout << endl;
            for (int i=0;i<4;++i)
                for (int j=0;j<4;++j)
                    for (int k=0;k<4;++k)
                        if (solve(a,i,j,k)) return true;
        } while (next_permutation(a.begin(),a.end()));
        
        return false;
    }
};

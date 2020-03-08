class Cashier {

    int cnt, N, disc;
    unordered_map<int, int> m;
    
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices):cnt(0), N(n), disc(discount){
        for(int i = 0; i < products.size(); ++i) m[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double sum = 0;
        for(int i = 0; i < product.size(); ++i) sum += m[product[i]]*amount[i];
        if(++cnt == N) sum -= (double)disc * sum / 100;
        cnt %= N;
        return sum;
    }

};

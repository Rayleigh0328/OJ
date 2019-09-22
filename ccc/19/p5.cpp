#include<cstdio>

using namespace std;

const int MAXSIZE=3001;
int f[MAXSIZE][MAXSIZE];
int g[MAXSIZE][MAXSIZE];
int n, k;

inline int max(int x, int y){
    return ((x > y)?x:y);
}

void solve(int a[][MAXSIZE] , int b[][MAXSIZE], int total_size, int sub_size){
   for (int i=0; i<total_size-sub_size+1;++i){
       for (int j=0;j<=i;++j)
           b[i][j] = max(a[i][j], max(a[i+1][j], a[i+1][j+1]));
   }
}

long long get_ans(int a[][MAXSIZE], int total_size, int sub_size){
    long long sum = 0ll; 
    for (int i=0; i<total_size - sub_size + 1; ++i)
       for (int j=0; j<=i; ++j) sum += a[i][j]; 
    return sum;
}

int main() {
    // populate a
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; ++i) 
        for (int j=0; j<=i; ++j)
            scanf("%d", &f[i][j]);
    for (int i=0; i<n+1; ++i) f[n][i] = -1;

    // iteratively calculate f,g
    for (int x = 2; x<=k; ++x){
        if ((x&1)==0) solve(f,g,n,x);
        else solve(g,f,n,x);
    }

    // get answer
    printf("%lld\n", (((k&1)==0)?get_ans(g, n, k):get_ans(f, n, k)) );

    return 0;
}

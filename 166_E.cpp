#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;
const int MOD = 1e9 + 7;
const int SZ = 4;

int add(int a, int b)
{
    int res = a + b;
    if(res >= MOD)
        return res - MOD;
    return res;
}

int mult(int a, int b)
{
    long long res = a;
    res *= b;
    if(res >= MOD)
        return res % MOD;
    return res;
}

struct matrix
{
    int arr[SZ][SZ];

    void reset()
    {
        memset(arr, 0, sizeof(arr));
    }

    void makeiden()
    {
        reset();
        for(int i=0;i<SZ;i++)
        {
            arr[i][i] = 1;
        }
    }

    matrix operator + (const matrix &o) const 
    {
        matrix res;
        for(int i=0;i<SZ;i++)
        {
            for(int j=0;j<SZ;j++)
            {
                res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
            }
        }
        return res;
    }

    matrix operator * (const matrix &o) const 
    {
        matrix res;
        for(int i=0;i<SZ;i++)
        {
            for(int j=0;j<SZ;j++)
            {
                res.arr[i][j] = 0;
                for(int k=0;k<SZ;k++)
                {
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, int b)
{
    matrix res;
    res.makeiden();
    while(b)
    {
        if(b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    matrix M;
    FOR(i,0,SZ-1) FOR(j,0,SZ-1) {
        if(i == j) 
            M.arr[i][j] = 0;
        else
            M.arr[i][j] = 1;
    }

    M = power(M,n);
    // all diagonal values in M will be same. Since, graph is symmetric.
    // Select any one answer (consider it as starting point)
    cout << M.arr[0][0] << '\n';
}

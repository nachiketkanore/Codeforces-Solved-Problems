#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

string s;

struct data
{
    //Use required attributes
    int four, seven, inc, dec;

    //Default Values
    data() : four(0), seven(0), inc(0), dec(0) {};
};

struct SegTree
{
    int N;
    vector<data> st;
    vector<int> cLazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, 0);
        build(1,1,n);
    }

    //Write reqd merge functions
    void merge(data &cur, data &l, data &r) 
    {
        cur.four = l.four + r.four;
        cur.seven = l.seven + r.seven;
        cur.inc = max({l.four + r.seven, l.inc + r.seven, l.four + r.inc});
        cur.inc = max({cur.inc, cur.four, cur.seven});
        cur.dec = max({l.seven + r.four, l.dec + r.four, l.seven + r.dec});
        cur.dec = max({cur.dec, cur.four, cur.seven});
    }
    
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R)
    {
        if(L != R)
        {
            cLazy[node*2] ^= 1;
            cLazy[node*2 + 1] ^= 1;
        }
        swap(st[node].four, st[node].seven);
        swap(st[node].inc, st[node].dec);
        cLazy[node] = 0;
        //Update lazy[node] after propogation if required
    }

    void build(int node, int L, int R)
    {
        if(L==R)
        {
            st[node].inc = st[node].dec = 1;
            if(s[L] == '4')
                st[node].four = 1;
            else 
                st[node].seven = 1; 
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    data Query(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return data();    //There might be changes required here
        if(i<=L && R<=j)
            return st[node];
        int M = (L + R)/2;
        data left=Query(node*2, L, M, i, j);
        data right=Query(node*2 + 1, M + 1, R, i, j);
        data cur;
        merge(cur, left, right);
        return cur;
    }

    void Update(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] ^= 1;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j);
        Update(node*2 + 1, M + 1, R, i, j);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    data query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int l, int r)
    {
        Update(1, 1, N, l, r);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, q;
    cin >> n >> q;
    cin >> s;
    s = " " + s;

    SegTree T;
    T.init(n);

    while(q--)
    {
        string t;
        cin >> t;
        if(t[0] == 'c')
        {
            cout << T.query(1,n).inc << '\n';
        }
        else
        {
            int L, R;
            cin >> L >> R;
            T.update(L,R);
        }
    }
}
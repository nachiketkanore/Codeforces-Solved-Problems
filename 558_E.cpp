/*
Thought I found a way
Thought I found a way out (Found)
But you never go away (Never go away)
So I guess I gotta stay now

Oh, I hope some day I'll make it out of here
Even if it takes all night or a hundred years
Need a place to hide, but I can't find one near
Wanna feel alive, outside I can't fight my fear

Isn't it lovely, all alone
Heart made of glass, my mind of stone
Tear me to pieces, skin to bone
Hello, welcome home

Walking out of time
Looking for a better place (Looking for a better place)
Something's on my mind
Always in my head space

But I know someday I'll make it out of here
Even if it takes all night or a hundred years
Need a place to hide, but I can't find one near
Wanna feel alive, outside I can't fight my fear

Isn't it lovely, all alone
Heart made of glass, my mind of stone
Tear me to pieces, skin to bone
Hello, welcome home
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

const int N = 2e5 + 2;

int n, q, i, j, k;

struct data
{
    //Use required attributes
    int mn;

    //Default Values
    data() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<data> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }

    //Write reqd merge functions
    void merge(data &cur, data &l, data &r) 
    {
        cur.mn = (l.mn + r.mn);
    }
    
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R)
    {
        if(L != R)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] = lazy[node];
            lazy[node*2 + 1] = lazy[node]; 
        }
        st[node].mn = lazy[node] * (R - L + 1);
        cLazy[node] = 0;
        //Update lazy[node] after propogation if required
    }

    void build(int node, int L, int R)
    {
        if(L==R)
        {
            st[node].mn = 1e9;
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

    data pQuery(int node, int L, int R, int pos)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
            return st[node];
        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }    

    void Update(int node, int L, int R, int i, int j, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    data query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    data query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
}st[26];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;

    for(int i = 0; i < 26; i++)
        st[i].init(n);

    for(int i = 1; i <= n; i++){
        st[s[i] - 'a'].update(i, 1);
    }

    while(q--)
    {
        int L, R, k;
        cin >> L >> R >> k;

        if(k)   //sorted
        {
            int id = L;
            for(int i = 0; i < 26; i++){
                int cnt = st[i].query(L, R).mn;
                st[i].update(L, R, 0);
                if(cnt > 0)
                    st[i].update(id, id + cnt - 1, 1);
                id += cnt;
            }
        }
        else    //sorted(reverse)
        {
            int id = L;
            for(int i = 25; i >= 0; i--){
                int cnt = st[i].query(L, R).mn;
                st[i].update(L, R, 0);
                if(cnt > 0)
                    st[i].update(id, id + cnt - 1, 1);
                id += cnt;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int too = 0;
        for(int j = 0; j < 26; j++)
            if(st[j].query(i).mn == 1){
                cout << (char)('a' + j);
                ++too;
            }
            assert(too == 1);
    }
}

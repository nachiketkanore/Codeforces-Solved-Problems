#include <bits/stdc++.h>
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int Q = 1e5 + 5;
const int SZ = 330;

struct data
{
    int l, r, idx;
}qr[Q];

int n, q, a[N];
int freq[N];
long long ans[Q];
long long cur = 0;

bool comp(struct data &d1, struct data &d2)
{
    int b1 = d1.l / SZ;
    int b2 = d2.l / SZ;
    if(b1 != b2)
        return b1 < b2;
    else
        return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void add(int x)
{   
    if(x > n) return;
    if(freq[x] == x){
        --cur;
        freq[x]++;
    }
    else{
        freq[x]++;
        cur += freq[x] == x;
    }
}

inline void remove(int x)
{   
    if(x > n) return;
    if(freq[x] == x){
        freq[x]--;
        --cur;
    }
    else{
        freq[x]--;
        cur += freq[x] == x;
    }
}

void mo()
{
    sort(qr + 1, qr + q + 1, comp);
    int l = 1, r = 0;
    cur = 0;
    for(int i=1;i<=q;i++)
    {
        while(l < qr[i].l) remove(a[l++]);
        while(l > qr[i].l) add(a[--l]);
        while(r < qr[i].r) add(a[++r]);
        while(r > qr[i].r) remove(a[r--]);
        ans[qr[i].idx] = cur;
    }
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL);  

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= q; i++){
        cin >> qr[i].l >> qr[i].r;
        qr[i].idx = i;
    }
    mo();
    for(int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}
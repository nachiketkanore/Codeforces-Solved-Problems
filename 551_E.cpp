#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 5e5 + 5, inf = 1e18;
const int BUCKET = 474;

int n, q, lazy[N];
pair<int,int> values[N];


/*---------------------------------------DEBUG-----------------------------------------------*/
void __print(int x) {
    cerr << x;
}
void __print(float x) {
    cerr << x;
}
void __print(double x) {
    cerr << x;
}
void __print(long double x) {
    cerr << x;
}
void __print(char x) {
    cerr << '\'' << x << '\'';
}
void __print(const char *x) {
    cerr << '\"' << x << '\"';
}
void __print(const string &x) {
    cerr << '\"' << x << '\"';
}
void __print(bool x) {
    cerr << (x ? "true" : "false");
}


template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';
}
template<typename T>
void __print(const T &x) {
    int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t); if (sizeof...(v)) cerr << ", "; _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif
/*---------------------------------------DEBUG-----------------------------------------------*/


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> q;
    FOR(i,1,n) {
        cin >> values[i].first;
        values[i].second = i;
    }
    for(int i = 1; i <= n; i += BUCKET) {
        sort(values + i, values + min(n, i + BUCKET - 1) + 1);
        //keep each bucket in sorted order
    }
    while(q--)
    {
        int tc;
        cin >> tc;
        if(tc == 1)
        {
            int L, R, add;
            cin >> L >> R >> add;
            for(int i = 1, which = 0; i <= n; ++which, i += BUCKET) {
                int from = i;
                int to = min(n, i + BUCKET - 1);
                //[from, to] : both inclusive
                if(to < L || R < from) continue;
                if(L <= from && to <= R) {
                    // update lazy
                    lazy[which] += add;
                    continue;
                }
                // full update bucket
                FOR(id,from,to) {
                    int index = values[id].second;
                    //only update indexes in given range [L, R]
                    if(L <= index && index <= R) {
                        values[id].first += add;
                    }
                }
                //sorting to keep bucket reusable later
                //[from, to] = [from, to + 1) for addresses
                sort(values + from, values + to + 1);
            }
        }
        else 
        {
            int val;
            cin >> val;
            int leftmost = inf, rightmost = -inf;

            for(int i = 1, which = 0; i <= n; i += BUCKET, ++which) {
                // a[i] + lazy[which] = val
                // to_find = val - lazy[which]
                int to_find = val - lazy[which];
                int L = 0, R = 0;

                int lo = i, hi = min(n, i + BUCKET - 1);

                while(lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if(values[mid].first >= to_find) {
                        L = mid;
                        hi = mid - 1;
                    }else lo = mid + 1;
                }
                lo = i, hi = min(n, i + BUCKET - 1);
                while(lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if(values[mid].first <= to_find) {
                        R = mid;
                        lo = mid + 1;
                    }else hi = mid - 1;
                }

                if(values[L].first != to_find || values[R].first != to_find)
                    continue;
                if(L <= R) {
                    leftmost = min(leftmost, values[L].second);
                    rightmost = max(rightmost, values[R].second);
                }
            }

            int ans = rightmost -leftmost;
            if(leftmost == inf) 
                ans = -1;
            cout << ans << '\n';
        }
    }
}

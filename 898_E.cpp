#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, a[N], make_square_cost[N], make_non_square_cost[N];
int squares, non_squares;

bool is_square(int x) {
    int root = (int)(sqrt(x));
    return root * root == x;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fill(make_square_cost, make_square_cost + N, inf);
    fill(make_non_square_cost, make_non_square_cost + N, inf);

    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        int root = (int)(sqrt(a[i]));
        int prev = root - 1, next = root + 1;
        if(prev >= 0) {
            make_square_cost[i] = min(make_square_cost[i], abs(a[i] - prev * prev));
        }
        make_square_cost[i] = min(make_square_cost[i], abs(a[i] - next * next));
        make_square_cost[i] = min(make_square_cost[i], abs(a[i] - root * root));
        FOR(val,a[i]-6,a[i]+6) if(val >= 0) {
            if(!is_square(val)) {
                make_non_square_cost[i] = min(make_non_square_cost[i], abs(a[i] - val));
            }
        }
        if(is_square(a[i])) ++squares;
        else ++non_squares;
    }

    vector<int> sum;
    int get = 0;

    int want = n / 2;
    if(squares > want) {
        get = squares - want;
        FOR(i,1,n) if(make_non_square_cost[i] > 0) {
            sum.push_back(make_non_square_cost[i]);
        }
    }else if(non_squares > want) {
        get = non_squares - want;
        FOR(i,1,n) if(make_square_cost[i] > 0) {
            sum.push_back(make_square_cost[i]);
        }
    }else {
        assert(squares == non_squares && squares == want);
        cout << 0 << '\n';
        return 0;
    }
    sort(sum.begin(), sum.end());
    cout << accumulate(sum.begin(), sum.begin() + get, 0LL);
}

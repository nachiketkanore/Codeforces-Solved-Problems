#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;

int n, a[N], b[N], c[N], order[N];

void compress(int arr[]) {
	vector<int> vals;

	FOR(i,1,n) vals.push_back(arr[i]);
	sort(vals.begin(), vals.end());

	FOR(i,1,n) arr[i] = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin(), ++arr[i];
}


class segTree{

   private:
      int n;
      vector<int> st;
   public:
      //Keeping it 1-based
      void init(int _n){
         n = _n;
         st = vector<int>(4 * n + 5,0);
      }

      void pointUpdate(int node, int tl, int tr, int pos, int val){
         if(tl == tr){
            st[node] = max(st[node], val);
         }else{
            int mid = (tl + tr)/2;
            if(pos <= mid)
               pointUpdate(2*node, tl, mid, pos, val);
            else
               pointUpdate(2*node + 1, mid + 1, tr, pos, val);
            st[node] = max(st[2 * node], st[2 * node + 1]); //operation
         }

      }

      int rangeQuery(int node, int tl, int tr, int l, int r){
         if(l > r) return -inf; //handle this value carefully
         if((l == tl) && (r == tr))
            return st[node];
         int mid = (tl + tr) / 2;
         int left_ans = rangeQuery(2*node, tl , mid, l, min(r,mid));
         int right_ans = rangeQuery(2*node + 1, mid + 1, tr, max(l, mid + 1), r);
         return max(left_ans, right_ans); //operation
      }

      void update(int pos, int val){
         pointUpdate(1, 1, n, pos, val);
      }

      int query(int l, int r){
      	 r = min(r, n);
         return rangeQuery(1, 1, n, l, r);
      }

} rangeMax;


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;

	FOR(i,1,n) cin >> a[i], order[i] = i;
	FOR(i,1,n) cin >> b[i];
	FOR(i,1,n) cin >> c[i];

	compress(a);
	compress(b);
	compress(c);
	rangeMax.init(N);

	sort (order + 1, order + n + 1, [&](int i, int j){
		return a[i] > a[j];
	});

	int ans = 0;

	int j = 0;
	for (int i = 1; i <= n; i = j) {
		while (j <= n && a[order[i]] == a[order[j]]) ++j;

		// Now we have valid condition for a[i] > a[j]
		for (int k = i; k < j; k++) {
			int id = order[k];
			// Now b[i] could be anything between [ b[id] + 1, ... , inf ]
			// So, for each of them we find max(c[]) such that max(c[]) could become > c[id]
			int get_max_c_for_valid_b = rangeMax.query(b[id] + 1, inf);
			if (get_max_c_for_valid_b > c[id]) 
				++ans;
		}

		for (int k = i; k < j; k++) {
			int id = order[k];
			rangeMax.update(b[id], c[id]);
		}
	}

	cout << ans;
}
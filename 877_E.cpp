#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+100;
int n, st[4*N], lz[4*N], light[N], flat[N], start[N], finish[N], timer;
std::vector<int> g[N];

void dfs(int node, int par){
	start[node] = ++timer;
	flat[timer] = node;
	for(int next : g[node]){
		if(next != par)
			dfs(next, node);
	}
	finish[node] = timer;
}

void build(int node, int tl, int tr){
	if(tl == tr)
		st[node] = light[flat[tl]];
	else{
		int mid = (tl + tr)/2;
		build(2*node, tl , mid);
		build(2*node+1, mid+1, tr);
		st[node] = st[2*node] + st[2*node+1];
	}
}

void push(int node, int l, int r){
	if(lz[node]){
		st[node] = (r - l + 1) - st[node];
		if(l != r){
			lz[2*node] ^= 1;
			lz[2*node + 1] ^= 1;
		}
			lz[node] = 0;
	}
}

void update(int tl, int tr, int node, int ql, int qr){
	push(node, tl, tr);
	if(qr < tl || tr < ql)
		return ;
	if(tl >= ql and tr <= qr){
		lz[node] ^= 1;
		push(node, tl, tr);
		return;
	}
	int mid = (tl + tr)/2;
	update(tl,mid,2*node, ql, qr);
	update(mid+1, tr, 2*node+1,ql,qr);
	st[node] = st[2*node] + st[2*node +1];
}

int query(int tl, int tr, int node, int ql, int qr){
	push(node, tl , tr);
	if(qr < tl || tr < ql)
		return 0;
	if(tl >= ql and tr <= qr)
		return st[node];
	int mid = (tl + tr)/2;
	return query(tl,mid,2*node, ql,qr) + query(mid+1,tr, 2*node + 1,ql,qr);
}

int query(int left, int right){
	return query(1,n,1,left,right);
}

void update(int left, int right){
	update(1,n,1,left,right);
}

int main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	for(int i = 2; i <= n; i++){
		int par;
		cin >> par;
		g[par].push_back(i);
		g[i].push_back(par);
	}
	dfs(1,0);
	for(int i = 1; i <= n; i++)
		cin >> light[i];
	build(1,1,n);

	int q;
	cin >> q;
	while(q--){
		string test;
		int node;
		cin >> test >> node;
		if(test == "pow")
			update(start[node], finish[node]);
		else
			cout << query(start[node], finish[node]) << '\n';
	}

}
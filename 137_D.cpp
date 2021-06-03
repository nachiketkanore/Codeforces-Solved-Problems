#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

const int N = 500 + 2, inf = 1e9;

string s;
vector<string> answer;
int k, n, cost[N][N], dp[N][N];

int go(int id, int groups){
	if(groups > k)
		return inf;
	if(id > n)
		return 0;
	int &ans = dp[id][groups];
	if(~ans)
		return ans;
	ans = inf;	
	for(int r = id; r <= n; r++){
		int req = cost[id][r] + go(r + 1, groups + 1);
		ans = min(ans, req);
	}
	return ans;
}

void find(int id, int groups){
	if(id > n)
		return ;
	
	int ans = go(id, groups);

	for(int r = id; r <= n; r++){
		int req = cost[id][r] + go(r + 1, groups + 1);
		if(req == ans){
			answer.push_back(s.substr(id, r - id + 1));
			return find(r + 1, groups + 1);
		}
	}
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> s >> k;
    n = sz(s);
    s = " " + s;
    for(int i = 1; i <= n; i++)
    	for(int j = i; j <= n; j++){
    		int &keep = cost[i][j];
    		int L = i, R = j;
    		while(L < R)
    			keep += s[L++] != s[R--];
    	}
    int minChanges = go(1, 0);
    cout << minChanges << '\n';

    find(1, 0);
    for(int i = 0; i < sz(answer); i++){

    	int L = 0, R = sz(answer[i]) - 1;
    	string &t = answer[i];
    	while(L < R)
    	{
    		if(t[L] != t[R])
    			t[L] = t[R];
    		L++, R--;
    	}
    	cout << t;
    	cout << "+\n"[i == sz(answer) - 1];
    }
}

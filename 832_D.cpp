#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2;

class Tree{
    public:
        void init (int _n){
            n = _n;
            edges = vector<vector<int>> (n + 1);
            tin = vector<int> (n + 1);
            tout = vector<int> (n + 1);
            level = vector<int> (n + 1);
        }

        void dfs(int k, int par, int lvl){
            tin[k] = ++time;
            parent[0][k] = par;
            level[k] = lvl;

            for(auto it : edges[k]){
                if(it == par)
                    continue;
                dfs(it, k, lvl+1);
            }
            tout[k] = time;
        }

        int walk(int u, int h){
            for(int i = LG-1; i >= 0; i--){
                if((h >> i) & 1)
                    u = parent[i][u];
            }
            return u;
        }

        void precompute(){
            for(int i = 1; i < LG; i++)
                for(int j = 1; j <= n; j++)
                    if(parent[i-1][j])
                        parent[i][j] = parent[i-1][parent[i-1][j]];
        }

        int LCA(int u, int v){
            if(level[u] < level[v])
                swap(u,v);
            int diff = level[u] - level[v];
            for(int i= LG-1; i >= 0; i--){
                if((1<<i) & diff){
                    u=parent[i][u];
                }
            }
            if(u == v)
                return u;
            for(int i = LG-1; i >= 0; i--){
                if(parent[i][u] && parent[i][u] != parent[i][v]){
                    u=parent[i][u];
                    v=parent[i][v];
                }
            }
            return parent[0][u];
        }

        bool isAncestor(int top , int bot){
            return (tin[top] <= tin[bot]) && (tout[bot] <= tout[top]);
        }

        int dist(int u, int v){
            return level[u] + level[v] - 2 * level[LCA(u, v)] + 1;
        }

        void setRoot(int u){
            dfs(u, 0, 1);
        }

        void setLCA(int u = 1){
            setRoot(u);
            precompute();
        }

        int getDepth(int u){
            return level[u];
        }

        void addEdge(int u, int v) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

    private:
        int n, time = 0;
        const int LG = 20;
        std::vector<int> tin, tout, level;
        std::vector<std::vector<int>> edges;
        int parent[21][N];

} T;

int solve(int f, int t, int s){
    //case 1 : f is in between s and t
    if(T.isAncestor(f,s) ^ T.isAncestor(f,t))
        return 1;
    //case 2 : f is above both s and t
    if(T.isAncestor(f,s) && T.isAncestor(f,t))
        return T.dist(T.LCA(s,t), f);
    
    int t1 = T.LCA(s, f);
    int t2 = T.LCA(t, f);
    //case 3 : sf and tf have same ancestor
    if(t1 == t2){
        return T.dist(T.LCA(s,t), f);
    }
    //case 4 : totally disjoint ancestors
    int ans = T.getDepth(f) - max(T.getDepth(t1), T.getDepth(t2)) + 1;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, q;
    cin >> n >> q;
    T.init(n);

    FOR(i,2,n){
        int v;
        cin >> v;
        T.addEdge(i,v);
    }
    
    T.setLCA(1);

    while(q--){
        std::vector<int> a(3);
        for(int &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        int ans = 0;
        do{
            ans = max(ans, solve(a[0], a[1], a[2]));
        }while(next_permutation(a.begin(), a.end()));
        cout << ans << '\n';
    }
}

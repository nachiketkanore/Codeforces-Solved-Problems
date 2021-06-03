//Let's start from scratch again
#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5+5;
vector<int> g[N];
int col[N];
bool yes = true, vis[N];

void bipartite(int start){
    queue<int> Q;
    Q.push(start);
    col[start] = 1;
    vis[start] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto v : g[u]){
            if(col[v] != -1 and col[v] == col[u]){
                yes = false;
                return;
            }
            vis[v] = 1;
            if(col[v] == -1){
                col[v] = 1 - col[u];
                Q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(col, -1, sizeof(col));
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            bipartite(i);
    }

    if(!yes){
        cout << -1 << endl;
    }else{
        int one = 0, zero = 0;
        for(int i = 1; i <= n; i++)
            one += col[i] == 1, 
            zero += col[i] == 0;
        cout << one << '\n';
        for(int i = 1; i <= n; i++)
            if(col[i] == 1)
                cout << i << ' ';
        cout << '\n';
        cout << zero << '\n';
        for(int i = 1; i <= n; i++)
            if(col[i] == 0)
                cout << i << ' ';
        cout << '\n';
    }

}
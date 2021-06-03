#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int B = 30;

struct Trie {
  struct node {
    node *nxt[2];
    int cnt;
    node() {
      nxt[0] = nxt[1] = NULL;
      cnt = 0;
    }
  };

  node *root;
  Trie() {
    root = new node();
  }

  void insert(int v) {
    node *curr = root;
    for (int i = B - 1; i >= 0; i--) {
      curr->cnt++;
      int b = (v >> i) & 1;
      if (curr->nxt[b] == NULL) curr->nxt[b] = new node();
      curr = curr->nxt[b];
    }
    curr->cnt++;
  }
  int query(int v) {
    int res = 0;
    node *curr = root;
    for (int i = B - 1; i >= 0; i--) {
      if (curr == NULL) break;
      int b = (v >> i) & 1;
      if (curr->nxt[b] == NULL) break;
      if (curr->nxt[b]->cnt < (1 << i)) {
        curr = curr->nxt[b];
      } else {
        curr = curr->nxt[1 - b];
        res ^= (1 << i);
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m; cin >> n >> m;
  Trie t;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    if (s.insert(v).second) t.insert(v);
  }
  int x = 0;
  for (int i = 0; i < m; i++) {
    int v; cin >> v;
    x ^= v;
    cout << t.query(x) << '\n';
  }
  return 0;
}

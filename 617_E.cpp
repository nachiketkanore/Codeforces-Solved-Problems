/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 06:43:30 PM IST
(ツ) The greatest part of our happiness depends on our dispositions, not our circumstances.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
using namespace std;
 
const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int M = 5e6 + 5;
const int SZ = sqrt(N) + 1;

struct data
{
	int l, r, idx;
}qr[Q];

int n, q, a[N], k;
int freq[M], ans[Q], cur = 0;

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
	cur += freq[x ^ k];
	freq[x]++;
}

inline void remove(int x)
{
	freq[x]--;
	cur -= freq[x ^ k];
}

void mo()
{
	sort(qr + 1, qr + q + 1, comp);
	int l = 0, r = 0;
	cur = 0;
	freq[0] = 1;
	for(int i=1;i<=q;i++)
	{
		while(l < qr[i].l) remove(a[l++]);
		while(l > qr[i].l) add(a[--l]);
		while(r < qr[i].r) add(a[++r]);
		while(r > qr[i].r) remove(a[r--]);
		ans[qr[i].idx] = cur;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], a[i] ^= a[i-1];
	for (int i = 1; i <= q; i++) {
		cin >> qr[i].l >> qr[i].r;
		--qr[i].l;
		qr[i].idx = i;
	}
	mo();
	for (int i = 1; i <= q; i++) 
		cout << ans[i] << '\n';
}

#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;


long long merge (int *arr, int left, int middle, int right) {
    int *temp = new int[right - left];
    memcpy(temp, arr + left, (right - left) * sizeof(int));
   
    int i1 = 0;
    int i2 = (right - left) / 2;
    long long inversions = 0;
    for (int i = 0; i < right - left; i++) {
        if ((i1 < (right - left) / 2) && (temp[i1] < temp[i2] || i2 >= (right - left))) {
            arr[left + i] = temp[i1++];
        } else {
            arr[left + i] = temp[i2++];
            inversions += (right - left) / 2 - i1;
        }
    }
    return inversions;
}

long long mergeSort(int *arr, int left, int right) {
    long long countA, countB, countC;
    countA = countB = countC = 0;
    if (right - left > 1) {
        int middle = left + (right-left)/2;
        
        countA = mergeSort(arr, left, middle);
        countB = mergeSort(arr, middle, right);
        
        countC = merge(arr, left, middle, right);
    }
    return countA + countB + countC;
}

long long sortCount(int *arr, int n) {
    if (n == 1) {
        return 0;
    } else {
        return mergeSort(arr, 0, n);
    }
}

vector<int> pos[26], npos[26];
int changed[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;	cin >> n;
	string s;	cin >> s;

	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}

	reverse(s.begin(), s.end());

	for (int i = 0; i < n; i++) {
		npos[s[i] - 'a'].push_back(i);
	}

	for (int ch = 0; ch < 26; ch++) {
		sort(pos[ch].begin(), pos[ch].end());
		sort(npos[ch].begin(), npos[ch].end());
		assert(sz(pos[ch]) == sz(npos[ch]));

		for (int i = 0; i < sz(pos[ch]); i++) {
			changed[pos[ch][i]] = npos[ch][i];
		}
	}

	int ans = sortCount(changed, n);
	cout << ans;
}

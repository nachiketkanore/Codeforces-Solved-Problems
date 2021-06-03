#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

string s;
int n, freq1[30][N], freq2[30][N];
bool is_vowel[257];
int pref[N], suff_max[N];

int get_freq(int L, int R, char ch) {
    if (ch >= 'a' && ch <= 'z') 
        return freq1[ch - 'a'][R] - freq1[ch - 'a'][L - 1];
    return freq2[ch - 'A'][R] - freq2[ch - 'A'][L - 1];
}

int get_consonants(int L, int R) {
    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) if (!is_vowel[ch])
        ans += get_freq(L, R, ch);
    for (char ch = 'A'; ch <= 'Z'; ch++) if (!is_vowel[ch])
        ans += get_freq(L, R, ch);
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    is_vowel['a'] = true;    is_vowel['e'] = true;    is_vowel['i'] = true;    is_vowel['o'] = true;
    is_vowel['u'] = true;    is_vowel['A'] = true;    is_vowel['E'] = true;    is_vowel['I'] = true;
    is_vowel['O'] = true;    is_vowel['U'] = true;

    cin >> s;
    n = sz(s);
    s = " " + s;

    FOR(i,1,n) {
        if (s[i] >= 'a' && s[i] <= 'z')     freq1[s[i] - 'a'][i]++;
        if (s[i] >= 'A' && s[i] <= 'Z')     freq2[s[i] - 'A'][i]++;

        for (int id = 0; id < 26; id++) {
            freq1[id][i] += freq1[id][i - 1];
            freq2[id][i] += freq2[id][i - 1];
        }

        pref[i] = (is_vowel[s[i]] ? -1 : +2);
        pref[i] += pref[i - 1];
    }

    suff_max[n] = pref[n];

    for (int i = n - 1; i >= 1; i--) {
        suff_max[i] = max(suff_max[i + 1], pref[i]);
    }

    int max_len = 0;

    FOR(L,1,n) {

        int lo = L, hi = n, rightmost = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (suff_max[mid] >= pref[L - 1]) {
                rightmost = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (~rightmost) {
            int len = rightmost - L + 1;
            max_len = max(len, max_len);
        }
    }

    if (max_len == 0) {
        cout << "No solution" << '\n';
        return 0;
    }

    int cnt = 0;

    FOR(L,1,n) if (L + max_len - 1 <= n) {
        int R = L + max_len - 1;
        int consonents = get_consonants(L, R);
        int vowels = (R - L + 1) - consonents;
        cnt += vowels <= 2 * consonents;
    }

    cout << max_len << ' ' << cnt << '\n';
}

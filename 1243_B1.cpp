/*
I saw you dancing in a crowded room
You look so happy when I'm not with you
But then you saw me, caught you by surprise
A single teardrop falling from your eye

I don't know why I run away
I'll make you cry when I run away

You could've asked me why I broke your heart
You could've told me that you fell apart
But you walked past me like I wasn't there
And just pretended like you didn't care

I don't know why I run away
I'll make you cry when I run away

Take me back 'cause I wanna stay
Save your tears for another
Save your tears for another day
Save your tears for another day

So, I made you think that I would always stay
I said some things that I should never say
Yeah, I broke your heart like someone did to mine
And now you won't love me for a second time

I don't know why I run away, oh, girl
Said I make you cry when I run away

Girl, take me back 'cause I wanna stay
Save your tears for another
I realize that I'm much too late
And you deserve someone better
Save your tears for another day (Ooh, yeah)
Save your tears for another day (Yeah)

I don't know why I run away
I'll make you cry when I run away

Save your tears for another day, ooh, girl
I said save your tears for another day

Save your tears for another day
Save your tears for another day
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt = 0;
        string s1, t1;

        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                s1.push_back(s[i]);
                t1.push_back(t[i]);
                ++cnt;
            }
        }

        bool found = false;

        if(cnt == 2){
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++){
                    swap(s1[i], t1[j]);
                    found |= s1 == t1;
                    swap(s1[i], t1[j]);
                }
        }
        cout << (cnt == 2 && found ? "Yes" : "No") << '\n';
    }   
}

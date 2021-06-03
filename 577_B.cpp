#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001],n,m,a[1001];
int eval(int pos,int sum,int flag)
{
    if(pos==n)
            return sum==0 && flag;
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    return dp[pos][sum]=eval(pos+1,(sum+a[pos])%m,1)||eval(pos+1,sum,flag);
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n>m)
        return cout<<"YES",0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<(eval(0,0,0)?"YES":"NO");
}
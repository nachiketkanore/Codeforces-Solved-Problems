#include "bits/stdc++.h"
using namespace std;

const int N=2e3+20,MAX=1e8;

int n,m,sx,sy,l,r,dp[N][N],ans;
char a[N][N];
deque <pair <int,int>> q;
bool vis[N][N];
int dx[]={-1,+1, 0, 0};
int dy[]={ 0, 0,-1,+1};

bool invalid(int x,int y)
{
	return min(x,y)<1 or x>n or y>m or a[x][y]=='*' or vis[x][y];
}

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&l,&r);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);

	q.push_back({sx,sy});
	dp[sx][sy]=0;
	vis[sx][sy]=true;
	while(not q.empty())
	{
		auto p=q.front();
		q.pop_front();

		for(int k=0;k<4;k++)
		{
			int x=p.first+dx[k],y=p.second+dy[k];
			if(invalid(x,y)) continue;
			if(k<2)
			{
				q.push_front({x,y});
				dp[x][y]=dp[p.first][p.second];
			}
			else
			{
				q.push_back({x,y});
				dp[x][y]=dp[p.first][p.second]+(k==3);
			}
			vis[x][y]=true;
		}
	}

	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			if(not vis[x][y]) continue;
			int rt=dp[x][y];
			int hdist=y-sy;
			int lt=rt-hdist;
			if(lt<=l and rt<=r) ans++;
		}
	}

	printf("%d",ans);
}
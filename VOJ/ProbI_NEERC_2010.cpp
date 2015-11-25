#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100007;

vector<pii> a[maxn];
int n,m,ans[maxn],d[maxn];

void BFS(){
	queue<int> q;q.push(n);
	d[n]=0;
	FOR(i,1,n-1) d[i]=oo;
	while(!q.empty()){
		int u=q.front(); q.pop();
		REP(i,sz(a[u])){
			int v=a[u][i].fi;
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}

int list[2][maxn],cnt[2],mark[maxn],markid;

//#include <conio.h>
int main(){
	freopen("ideal.in","r",stdin);
	freopen("ideal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v,c;
	REP(i,m){
		scanf("%d%d%d",&u,&v,&c);
		a[u].pb(pii(v,c));
		a[v].pb(pii(u,c));
	}
    BFS();
	cnt[1]=1; list[1][0]=1;
	int flag=1;
	reset(mark,0); markid=0;
	FOR(i,1,d[1]){
		ans[i]=oo;
		REP(j,cnt[flag]){
			int u=list[flag][j];
			REP(z,sz(a[u])){
				int v=a[u][z].fi, c=a[u][z].se;
				if(d[v]+i!=d[1]) continue;
				if(ans[i]>c){
					ans[i]=c;
					markid++;
					cnt[1-flag]=1; list[1-flag][0]=v;
					mark[v]=markid;
				}else if(ans[i]==c && mark[v]!=markid){
					list[1-flag][cnt[1-flag]++]=v;
					mark[v]=markid;
                }
			}
		}
		flag=1-flag;
	}
	
	printf("%d\n",d[1]);
	FOR(i,1,d[1]) printf("%d ",ans[i]);
//	getch();
	return 0;
}

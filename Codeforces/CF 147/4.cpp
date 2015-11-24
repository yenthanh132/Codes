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

const int maxn= 100007;

vector<int> a[maxn];
map<pii,bool> mark;
map<pii,int> id;
int n,deg[maxn];

void DFS(int u, int v){
	int x,y;
	REP(i,sz(a[v])){
		x=a[v][i];
		if(x==u) continue;
		if(!mark[pii(v,x)]){
			mark[pii(v,x)]=mark[pii(x,v)]=1;
			printf("%d %d\n",id[pii(u,v)],id[pii(v,x)]);
			DFS(v,x);
		}
	}
}


int main(){
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int u,v;
	
	printf("%d\n",n-1);
	reset(deg,0);
	FOR(i,1,n-1){
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		a[u].pb(v);
		a[v].pb(u);
		id[pii(u,v)]=i;
		id[pii(v,u)]=i;
		deg[u]++; deg[v]++;
		printf("2 %d %d\n",u,v);
	}
	
	u=0; FOR(i,1,n) if(deg[i]==1){u=i; break;}
	mark[pii(u,a[u][0])]=mark[pii(a[u][0],v)]=0;
	DFS(u,a[u][0]);
	return 0;
}
	
	
	

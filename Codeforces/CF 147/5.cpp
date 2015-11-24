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

const int maxn = 200;

int start,finish,n,N,lent,c[maxn][maxn],f[maxn][maxn],a[maxn][maxn];
int trace[maxn],d[maxn];
bool free1[maxn];

string t;

int dis(int v){
	if(v>=0) return 1; else return -1;
}

bool findpath(){
	reset(free1,1); free1[start]=0;
	FOR(u,1,N) d[u]=oo;
	queue<int> q; q.push(start); d[start]=0;
	int u,v;
	while(!q.empty()){
		u=q.front(); q.pop(); free1[u]=1;
		FOR(v,1,N) if(c[u][v]>f[u][v] && d[v]>d[u]+a[u][v]*dis(f[u][v])){
			d[v]=d[u]+a[u][v]*dis(f[u][v]);
			trace[v]=u;
			if(free1[v]){
				q.push(v);
				free1[v]=0;
			}
		}
	}
	return(d[finish]!=oo);
}

void incflow(){
	int u,v=finish,delta=oo;
	while(v!=start){
		u=trace[v];
		if(f[u][v]>=0)
			delta=min(delta,c[u][v]-f[u][v]);
		else
			delta=min(delta,-f[u][v]);
		v=u;
	}
	v=finish;
	while(v!=start){
		u=trace[v];
		f[u][v]+=delta;
		f[v][u]-=delta;
		v=u;
	}
}

int main(){
	freopen("test.txt","r",stdin);
	cin>>t; lent=sz(t);
	cin>>n;
	N=n+26+2;
	start=N-1; finish=N;
	reset(c,0); reset(f,0); reset(a,0);
	REP(i,sz(t)) c[n+t[i]-'a'+1][finish]++;
	
	int v;
	FOR(i,1,n){
		cin>>t>>v;
		c[start][i]=v;
		REP(j,sz(t)) c[i][n+t[j]-'a'+1]++;
		FOR(j,1,26) a[i][n+j]=i;
	}
	while(findpath()) incflow();	
	int flowval=0;
	FOR(u,1,N) flowval+=f[u][finish];
	if(flowval<lent) puts("-1");
	else{
		int res=0;
		FOR(u,1,N) FOR(v,1,N) if(f[u][v]>0 && a[u][v]>0) res+=f[u][v]*a[u][v];
		cout<<res<<endl;
	}
	return 0;
}

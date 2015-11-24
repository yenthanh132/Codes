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

const int maxn = 11;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

bool free1[maxn][maxn];
int n,a[maxn][maxn],res;

void dfs(int x, int y){
	if(x==n && y==n){
		res++;
		return;
	}
	free1[x][y]=0;
	REP(k,4){
		int xt=x+dx[k], yt=y+dy[k];
		if(1<=xt && xt<=n && 1<=yt && yt<=n && free1[xt][yt] && a[xt][yt]==0) dfs(xt,yt);
	}
	free1[x][y]=1;
}

int main(){
//	freopen("test.txt","r",stdin);
	cin>>n;
	FOR(i,1,n) FOR(j,1,n) cin>>a[i][j];
	res=0;
	reset(free1,1);
	dfs(1,1);
	cout<<res<<endl;
	return 0;
}

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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 27;
int k[maxn],w[maxn],h[maxn],n,res,x,y;
char ch[maxn];

void DFS(int i, int x, int y){
	if(i==0){
		res++;
		return;
	}
	
	if(ch[i]=='B'){
		if(k[i]<=h[i-1]/2){
			if(y<k[i]) DFS(i-1,x,k[i]-y);
			DFS(i-1,x,k[i]+y);
		}else{
			if(y<h[i-1]-k[i]) DFS(i-1,x,h[i]+y);
			DFS(i-1,x,h[i]-y);
		}
	}else if(ch[i]=='T'){
		if(k[i]<=h[i-1]/2){
			if(h[i]-y<k[i]) DFS(i-1,x,h[i]+h[i]-y);
			DFS(i-1,x,y);
		}else{
			if(h[i]-y<h[i-1]-k[i]) DFS(i-1,x,y-(k[i]*2-h[i-1]));
			DFS(i-1,x,(h[i-1]-k[i])+(h[i]-y));
		}
	}else if(ch[i]=='L'){
		if(k[i]<=w[i-1]/2){
			if(x<k[i]) DFS(i-1,k[i]-x,y);
			DFS(i-1,k[i]+x,y);
		}else{
			if(x<w[i-1]-k[i]) DFS(i-1,w[i]+x,y);
			DFS(i-1,w[i]-x,y);
		}
	}else if(ch[i]=='R'){
		if(k[i]<=w[i-1]/2){
			if(w[i]-x<k[i]) DFS(i-1,w[i]+w[i]-x,y);
			DFS(i-1,x,y);
		}else{
			if(w[i]-x<w[i-1]-k[i]) DFS(i-1,x-(k[i]*2-w[i-1]),y);
			DFS(i-1,(w[i-1]-k[i])+(w[i]-x),y);
		}
	}
}
				

int main(){
	//freopen("game-999.inp","r",stdin);
	while(scanf("%d%d%d\n",w,h,&n),w[0]){
		FOR(i,1,n){
			scanf("%c %d\n",ch+i,k+i);
			w[i]=w[i-1]; h[i]=h[i-1];
			if(ch[i]=='B' || ch[i]=='T') h[i]=max(k[i],h[i-1]-k[i]); else w[i]=max(k[i],w[i-1]-k[i]);
		}
		scanf("%d %d\n",&x,&y);
		res=0;
		DFS(n,x,y);
		printf("%d\n",res);
	}
	return 0;
}


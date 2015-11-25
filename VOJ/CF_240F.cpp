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
struct node{int v,t;} IT[26][maxn*4];
int n,m,cnt[26];

void lazyupdate(int &ch, int &i, int &l, int &r){
	if(IT[ch][i].t==0) return;
	if(IT[ch][i].t==1) IT[ch][i].v=r-l+1; else IT[ch][i].v=0;
	if(l<r)
		IT[ch][i*2].t=IT[ch][i*2+1].t=IT[ch][i].t;
	IT[ch][i].t=0;
}

void update(int ch, int i, int l, int r, int s, int f, int v){
	lazyupdate(ch,i,l,r);
	if(f<l || r<s) return;
	if(s<=l && r<=f){
		IT[ch][i].t=v;
		lazyupdate(ch,i,l,r);
		return;
	}
	int mid=(l+r)/2;
	update(ch,i*2,l,mid,s,f,v);
	update(ch,i*2+1,mid+1,r,s,f,v);
	IT[ch][i].v=IT[ch][i*2].v+IT[ch][i*2+1].v;
}

int ansIT;
void getsum(int ch, int i, int l, int r, int s, int f){
	lazyupdate(ch,i,l,r);
	if(f<l || r<s) return;
	if(s<=l && r<=f){
		ansIT+=IT[ch][i].v;
		return;
	}
	int mid=(l+r)/2;
	getsum(ch,i*2,l,mid,s,f);
	getsum(ch,i*2+1,mid+1,r,s,f);
	IT[ch][i].v=IT[ch][i*2].v+IT[ch][i*2+1].v;
}
		

int main(){
//	freopen("test.txt","r",stdin);0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d\n",&n,&m);
	char ch;
	FOR(i,1,n){
		scanf("%c",&ch);
		update(ch-'a',1,1,n,i,i,1);
	}
	int l,r,u;
	FOR(index,1,m){
		scanf("%d%d",&l,&r);
		u=-1;
		REP(ch,26){
			ansIT=0;
			getsum(ch,1,1,n,l,r);
			cnt[ch]=ansIT;
			if(cnt[ch]&1) if(u==-1) u=ch; else u=oo;
		}
		if(u==oo) continue;
		REP(ch,26) update(ch,1,1,n,l,r,2);
		if(u!=-1) update(u,1,1,n,(l+r)/2,(l+r)/2,1), cnt[u]--;
		REP(ch,26) if(cnt[ch]>0){
			cnt[ch]/=2;
			update(ch,1,1,n,l,l+cnt[ch]-1,1);
			update(ch,1,1,n,r-cnt[ch]+1,r,1);
			l+=cnt[ch]; r-=cnt[ch];
		}
		
	}
	
	FOR(i,1,n)
		REP(ch,26){
			ansIT=0;
			getsum(ch,1,1,n,i,i);
			if(ansIT>0){
				putchar(ch+'a');
				break;
			}
		}
	puts("");
	return 0;
}

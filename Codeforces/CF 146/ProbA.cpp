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

int m,k,n,Min[101],Max[101];
bool fav[101];


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>m>>k;
	reset(fav,0);
	int v,d,t,t2,v1,v2;
	REP(i,k){
		cin>>v;
		fav[v]=1;
	}
	cin>>n;
	string s;
	FOR(i,1,n){
		cin>>s;
		cin>>d;
		t=t2=0;
		REP(j,d){
			cin>>v;
			if(v){
				if(fav[v]) t++;
			}
			else t2++;
		}
		v1=m-k-(d-t-t2);
		v2=k-t;
		Min[i]=t+max(0,t2-v1);
		Max[i]=t+min(v2,t2);
	}
	
	FOR(i,1,n){
		//cout<<Min[i]<<' '<<Max[i]<<endl;
		v1=0; v2=0;
		FOR(j,1,n) if(j!=i) v1=max(v1,Min[j]), v2=max(v2,Max[j]);
		if(Max[i]<v1) cout<<1;
		else if(Min[i]>=v2) cout<<0;
		else cout<<2;
		cout<<endl;
	}
	return 0;
}
	


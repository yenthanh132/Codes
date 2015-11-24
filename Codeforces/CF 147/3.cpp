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

const int maxn=1000000;

bool prime[1000007];
int a,b,k;

bool check(int l){
	int v=0;
	FOR(i,a,a+l-1) v+=prime[i];
	if(v<k) return 0;
	FOR(i,a,b-l){
		v+=prime[i+l]-prime[i];
		if(v<k) return 0;
	}
	return 1;
}

int main(){
	reset(prime,0);
	prime[2]=1;
	for(int i=3; i<=maxn; i+=2) prime[i]=1;
	for(int i=3;i*i<=maxn;i+=2) if(prime[i])
		for(int j=i*i; j<=maxn; j+=2*i) prime[j]=0;
	cin>>a>>b>>k;
	int left,right,mid,res=oo;
	left=1; right=b-a+1;
	while(left<=right){
		mid=(left+right)/2;
		if(check(mid)){
			res=mid;
			right=mid-1;
		}else left=mid+1;
	}
	if(res==oo) cout<<-1<<endl; else cout<<res<<endl;
	return 0;
}


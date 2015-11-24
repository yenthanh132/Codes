#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define pb push_back
#define fs first
#define sc second
#define openfile {freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}
#define debug 01

int a[20],n;
bool found;
bool mark[20][20];
int num[20][6],ans[20][6];

vector< int > part[10];

void dfs(int p, int v){
	if(found) return;
	if(p>n){
		if(v==0){
			found=1;
			for(int i=1; i<=n; ++i)	for(int j=0; j<6; ++j) ans[i][j]=num[i][j];
		}
		return;	
	}
	
	if(mark[p][v]) return;
	mark[p][v]=1;
	int val=a[p]-v;
	int t=0;
	if(val<0){
		val+=10;
		t=1;
	}
	for(int i=0; i<int(part[val%10].size()); ++i){
		int id=part[val%10][i];
		int sum=0;
		for(int j=0; j<6; ++j){
			int x=id%3;
			id/=3;
			if(x==1) x=4; else if(x==2) x=7;
			num[p][j]=x;
			sum+=x;
		}
		dfs(p+1,sum/10+t);
		if(found) break;
	}
}

void solve(ll v){
	found=0;
	n=0;
	while(v){
		a[++n]=v%10;
		v/=10;
	}
	
	memset(mark,0,sizeof(mark));
	
	dfs(1,0);
	if(!found) puts("-1");
	else{
		ll r[6];
		memset(r,0,sizeof(r));
		ll d=1;
		for(int i=1; i<=n; ++i){
			for(int j=0; j<6; j++) r[j]+=ans[i][j]*d;
			d*=10;
		}	
		for(int j=0; j<6; j++) cout<<r[j]<<' ';
		cout<<endl;
	}
}

void init(){
	for(int i=0; i<729; i++){
		int sum=0, id=i;
		int high=100;
		bool ok=1;
		for(int j=0; j<6; ++j){
			int t=id%3;
			if(high<t){
                ok=0;
                break;
            }else high=t;
			id/=3;
			if(t==1) sum+=4; else if(t==2) sum+=7;	
		}
		if(ok) part[sum%10].pb(i);
	}
	
}

int main() {
	init();
    if (debug) openfile;
    int t;
    long long v;
    cin>>t;
    for(int i=0; i<t; i++){
		cin>>v;
		solve(v);
	}	
	return 0;
}

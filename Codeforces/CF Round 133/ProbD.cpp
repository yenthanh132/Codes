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

const int maxn = 1007;

vector<int> p[maxn],d[maxn],d2[maxn];
int n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int k,v,j;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&k);
        REP(j,k){
            scanf("%d",&v);
            p[i].pb(v);
        }
        d[i].resize(k,0);
        d2[i]=d[i];
        sort(p[i].begin(),p[i].end());
    }
    
    
    FOR(i,1,n){
        if(i==1) j=n; else j=i-1;
        v=-1;
        REP(x,sz(p[i])){
            while(v<sz(p[j])-1 && p[j][v+1]<p[i][x]) v++;
            if(0<=v && v<sz(p[j])-1) d[j][v]++;
        }
    }
    
    FORD(i,n,1){
        if(i==n) j=1; else j=i+1;
        v=-1;
        REP(x,sz(p[i])){
            while(v<sz(p[j])-1 && p[j][v+1]<p[i][x]) v++;
            if(0<=v && v<sz(p[j])-1) d2[j][v]++;
        }
    }
    
    int res=0;
    FOR(i,1,n) REP(j,sz(p[i])-1) if(d[i][j]!=d2[i][j]) res++;
    printf("%d\n",res);
    //getch();
    return 0;
}

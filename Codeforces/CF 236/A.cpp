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

int deg[50],n,p;
int a[50][50];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    REP(tt,t){
        cin>>n>>p;
        reset(deg,0);
        reset(a,0);
        REP(i,2*n+p){
            int u=-1;
            FOR(x,1,n) if(u==-1 || deg[u]>deg[x]) u=x;
            int v=-1;
            FOR(x,1,n) if(a[u][x]==0 && x!=u && (v==-1 || (deg[v]>deg[x]))) v=x;
            deg[u]++; deg[v]++;
            a[u][v]=a[v][u]=1;
            printf("%d %d\n",u,v);            
        }   
    }

}

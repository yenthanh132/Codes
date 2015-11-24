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
typedef pair<ll, int> pii;

const int maxn=7000;
const int dmod=747474747;
int T,n,d,cnt,id[maxn],lab[maxn];
ll res;
int a[maxn][6];
struct node{
    ll v;
    int x,y;
}list[maxn*maxn];


ll sqr(ll v){return v*v;}

ll dis(int u, int v){
    ll res=0;
    FOR(k,1,d) res+=sqr(a[u][k]-a[v][k]);
    return res;
}

bool cmp(const int &a, const int &b){
    return list[a].v > list[b].v;
}

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&d);
        FOR(i,1,n) FOR(j,1,d) scanf("%d",&a[i][j]);
        cnt=0;
        const int chose=2;
        node maxlist[chose];
        FOR(i,1,n-1){
            node t;
            REP(j,chose) maxlist[j].v=-1;
            FOR(j,i+1,n){
                t.v=dis(i,j);
                t.x=i; t.y=j;
                REP(z,chose) if(maxlist[z].v < t.v){
                    FORD(z2,chose-1,z+1) maxlist[z2]=maxlist[z2-1];
                    maxlist[z]=t;
                    break;
                }
            }
            REP(j,chose) if(maxlist[j].v!=-1) list[++cnt]=maxlist[j];
        }
        FOR(i,1,cnt) id[i]=i;
        FOR(i,1,n) lab[i]=-1;
        sort(id+1,id+cnt+1,cmp);
        int ce=0,r1,r2;
        res=1;
        FOR(i,1,cnt){
            node &t=list[id[i]];
            r1=getroot(t.x); r2=getroot(t.y);
            if(t.v==0) break;
            if(r1!=r2){
                res=(res*(t.v%dmod))%dmod;
                dsu(r1,r2);
                ce++;
                if(ce==n-1) break;
            }
        }
        printf("%lld\n",res);
    }
    
    //getch();
    return 0;
}

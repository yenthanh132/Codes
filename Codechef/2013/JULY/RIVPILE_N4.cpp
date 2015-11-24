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
typedef pair<int, pii> iii;
const int maxn=257;

int d[maxn][maxn],r[maxn],c[maxn],x[maxn],y[maxn];
bool free1[maxn][maxn];
int n,m,w;
set<iii> mys;
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d%d",&n,&m,&w);
        FOR(i,1,n) scanf("%d%d",&x[i],&y[i]);
        FOR(i,1,m) scanf("%d%d",&r[i],&c[i]);
        mys.clear();
        FOR(i,1,n) FOR(j,1,m){
            if(r[j] < y[i]) d[i][j]=oo;
            else{
                d[i][j]=c[j];
                mys.insert(iii(c[j],pii(i,j)));
            }
        }
        reset(free1,1);
        int I,J,minv,res=oo;
        while(!mys.empty()){
            I=mys.begin()->se.fi; 
            J=mys.begin()->se.se;
            mys.erase(mys.begin());
            free1[I][J]=0;
            if(res<=d[I][J]){
                //cout<<res<<' '<<d[I][J];
                break;
            }
            if(r[J]>=w-y[I]) res=min(res,d[I][J]);
            FOR(i,1,n) FOR(j,1,m) 
                if(1ll*(x[i]-x[I])*(x[i]-x[I]) + 1ll*(y[i]-y[I])*(y[i]-y[I]) <= 1ll*(r[j] + r[J])*(r[j] + r[J]))
                    if(free1[i][j] && d[i][j]>d[I][J]+c[j]){
                        if(d[i][j]!=oo) mys.erase(mys.find(iii(d[i][j],pii(i,j))));
                        d[i][j]=d[I][J]+c[j];
                        mys.insert(iii(d[i][j],pii(i,j)));
                    }
        }   
        if(res==oo) puts("impossible"); else printf("%d\n",res);
    }
    getch();
}

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

const int maxn=100007;

int n,m,q,a[maxn],lab[maxn],ans[maxn],res;
pii e[maxn];
bool mark[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    int r=getroot(lab[u]);
    lab[u]=r; return r;
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
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n) lab[i]=-1;
    FOR(i,1,m) scanf("%d%d",&e[i].fi,&e[i].se);
    FOR(i,1,q){
        scanf("%d",&a[i]);
        mark[a[i]]=1;
    }
    res=n;
    int r1,r2;
    FOR(i,1,m) if(!mark[i]){
        r1=getroot(e[i].fi); r2=getroot(e[i].se);
        if(r1!=r2){
            dsu(r1,r2);
            res--;
        }
    }
    FORD(i,q,1){
        ans[i]=res;
        r1=getroot(e[a[i]].fi); r2=getroot(e[a[i]].se);
        if(r1!=r2){
            dsu(r1,r2);
            res--;
        }
    }
    FOR(i,1,q) printf("%d\n",ans[i]);
    //getch();
    return 0;
}
    

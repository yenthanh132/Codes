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
const int maxT=333;

ll val[maxn],a[maxn],add[maxn];
vector<int> list[maxn],f[maxn],biglist[maxn];
int n,m,q,cbig,pos[maxn],arrBig[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    int k,v;
    cbig=0;
    FOR(i,1,m){
        val[i]=0;
        scanf("%d",&k);
        if(k>maxT){
            ++cbig;
            arrBig[cbig]=i;
            pos[i]=cbig;
        }
        val[i]=add[i]=0;
        REP(j,k){
            scanf("%d",&v);
            list[i].pb(v);
            if(k>maxT) biglist[v].pb(cbig);
            val[i]+=a[v];
        }
    }

    FOR(i,1,m){
        f[i].resize(cbig+1,0);
        REP(j,sz(list[i])){
            v=list[i][j];
            REP(z,sz(biglist[v]))
                f[i][biglist[v][z]]++;
        }
    }

    char ch[10];
    REP(i,q){
        scanf("%s",ch);
        if(ch[0]=='?'){
            scanf("%d",&k);
            ll res=0;
            FOR(j,1,cbig) res+=f[k][j]*add[j];
            if(sz(list[k])<=maxT){
                REP(j,sz(list[k])) res+=a[list[k][j]];
            }else res+=val[k];
            printf("%I64d\n",res);
        }else{
            scanf("%d %d",&k,&v);
            if(sz(list[k])<=maxT){
                REP(j,sz(list[k])) a[list[k][j]]+=v;
                FOR(j,1,cbig) val[arrBig[j]]+=1ll*f[k][j]*v;
            }else add[pos[k]]+=v;
        }
    }
}


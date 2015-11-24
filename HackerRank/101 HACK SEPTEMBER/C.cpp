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
typedef pair<ll, int> pli;

const int maxn=11;
const int maxc=100007;
const int maxk=107;
const ll hash_base=73471;
const ll hash_base2=13021994;

ll val[2][maxc],hashpw[2][maxc],kval[2][256][maxk];
char s[maxn][maxc],st[maxc];
int a[maxn],n,k,klen[256][maxk],kcnt[256],d[maxc];

ll dis[maxc];
bool free1[maxc];

set<pli> mys;

void dijkstra(){
    int vmod=a[1];
    REP(j,vmod) dis[j]=oo;
    dis[0]=0;
    mys.insert(pli(0,0));
    reset(free1,1);
    int u,v;
    while(!mys.empty()){
        u=mys.begin()->se; mys.erase(mys.begin());
        free1[u]=0;
        FOR(i,1,n){
            v=(u+a[i])%vmod;
            if(free1[v] && dis[v]>dis[u]+a[i]){
                if(dis[v]!=oo) mys.erase(mys.find(pli(dis[v],v)));
                dis[v]=dis[u]+a[i];
                mys.insert(pli(dis[v],v));
            }
        }
    }    
}

//#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n); gets(st+1);
    FOR(i,1,n) gets(s[i]+1);
    
    scanf("%d",&k); gets(st+1);
    reset(kcnt,0);
    FOR(i,1,k){
        gets(st+1);
        int len=strlen(st+1);
        int id=++kcnt[st[len]];
        kval[0][st[len]][id]=0;
        klen[st[len]][id]=len;
        FOR(j,1,len){
            kval[0][st[len]][id]=kval[0][st[len]][id]*hash_base + st[j];
            kval[1][st[len]][id]=kval[1][st[len]][id]*hash_base2+ st[j];
        }
    }
    
    hashpw[0][0]=1;
    hashpw[1][0]=1;
    FOR(i,1,100000){
        hashpw[0][i]=hashpw[0][i-1]*hash_base;
        hashpw[1][i]=hashpw[1][i-1]*hash_base2;
    }
    int n2=0;
    FOR(i,1,n){
        int len=strlen(s[i]+1),len2;
        ll hash_val , hash_val2;
        val[0][0]=0;
        val[1][0]=0;
        FOR(j,1,len) d[j]=0;
        FOR(j,1,len){
            val[0][j]=val[0][j-1]*hash_base + s[i][j];
            val[1][j]=val[1][j-1]*hash_base2 + s[i][j];
            FOR(z,1,kcnt[s[i][j]]) if(j>=(len2=klen[s[i][j]][z])){
                hash_val = val[0][j] - val[0][j-len2]*hashpw[0][len2];
                hash_val2 = val[1][j] - val[1][j-len2]*hashpw[1][len2];
                if(hash_val == kval[0][s[i][j]][z] && hash_val2 == kval[1][s[i][j]][z]){
                    d[j-len2+1]++;
                    d[j+1]--;
                }
            }
        }
        a[i]=0;
        int x=0;
        FOR(j,1,len){
            x+=d[j];
            if(!x) a[i]++;
        }
        if(a[i]>0) a[++n2]=a[i];
    }
    n=n2;
    
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-(a+1);
    dijkstra();
    if(n==0) puts("-1");
    else{
        int vmod=a[1];
        ll maxv=0;
        REP(j,vmod) if(dis[j]==oo){
            maxv=oo;
            break;
        }else{
            ll v=dis[j]-vmod;
            maxv=max(maxv,v);
        }
    
        if(maxv==oo) puts("-1");
        else cout<<maxv<<endl;
    }
    
    //getch();
    return 0;
}            
    
    

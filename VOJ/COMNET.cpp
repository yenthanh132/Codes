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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}


const int maxn=100007;
const int maxm=1000007;

struct edge{int x,y,w,id;} e[maxm],elist[maxm];
int n,m,q,k,klen,s,lab[maxn],mark[maxm];
vector<pii> a[maxm],liste;
vector<int> listmark;

bool cmpe(const edge &a, const edge &b){return a.w<b.w;}

inline int getroot(int &u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

inline void dsu(int &u, int &v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

inline int findpos(int v){
    int l=1,r=m,mid,res=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(e[mid].w<=v){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return res;
}          

inline bool connected(int &id){
    return getroot(elist[id].x) == getroot(elist[id].y);
}

int main(){
    int test,pos,t,c,u,v;
    bool stop,ok;
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    read(test);
    REP(index,test){
        read(n); read(m); read(q);
        FOR(i,1,m){
            read(e[i].x); read(e[i].y); read(e[i].w);
            e[i].id=i;
            elist[i]=e[i];
        }
        sort(e+1,e+m+1,cmpe);
        reset(mark,0);
        FOR(index2,1,q){
            FOR(i,1,n) lab[i]=-1;
            read(k); read(s);
            klen=elist[k].w;
            liste.clear(); listmark.clear();
            REP(i,s){
                read(t); read(c);
                liste.pb(pii(c,t));
                mark[t]=index2;
                if(t==k) klen=c;
            }
            sort(liste.begin(),liste.end());
            REP(i,s){
                pos=findpos(liste[i].fi);
                a[pos].pb(liste[i]);
                listmark.pb(pos);
            }
            
            stop=ok=0;
            
            REP(i,sz(a[0])){
                u=elist[a[0][i].se].x;
                v=elist[a[0][i].se].y;
                dsu(u,v);
                if(connected(k)){
                    ok=a[0][i].fi<klen;
                    stop=1;
                    break;
                }
            }
            for(int i=1; !stop && i<=m; i++){
                if(mark[e[i].id]!=index2){
                    dsu(e[i].x,e[i].y);
                    if(connected(k)){
                        ok=e[i].w<klen;
                        stop=1;
                        break;
                    }
                }
                for(int j=0; !stop && j<sz(a[i]); j++){
                    u=elist[a[i][j].se].x;
                    v=elist[a[i][j].se].y;
                    dsu(u,v);
                    if(connected(k)){
                        ok=a[i][j].fi<klen;
                        stop=1;
                        break;
                    }
                }
            }
            
            if(ok) puts("YES"); else puts("NO");
            
            REP(i,s) a[listmark[i]].clear();
        }
    }
    return 0;
}
            
        

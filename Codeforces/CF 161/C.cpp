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

const int maxn=100017;

int n,deg[maxn],arr[maxn],res[maxn];
vector<int> a[maxn];
bool free1[maxn];

bool check(){
    int c,v;
    reset(free1,1);
    FOR(i,1,4) free1[arr[i]]=0;
    arr[n+1]=arr[1];
    arr[n+2]=arr[2];
    arr[n+3]=arr[3];
    arr[n+4]=arr[4];
    FOR(i,3,n-2){
        c=0;
        REP(j,sz(a[arr[i]])){
            v=a[arr[i]][j];
            if(v==arr[i-1]) c++;
            else if(v==arr[i-2]) c++;
            else if(v==arr[i+1]) c++;
            else{
                arr[i+2]=v;
                if(!free1[v]) return 0;
                free1[v]=0;
            }
        }
        if(c!=3) return 0;
    }
    FOR(i,n-1,n+2){
        c=0;
        REP(j,sz(a[arr[i]])){
            v=a[arr[i]][j];
            if(v==arr[i-1]) c++;
            else if(v==arr[i-2]) c++;
            else if(v==arr[i+1]) c++;
            else if(v==arr[i+2]) c++;
        }
        if(c!=4) return 0;
    }
    return 1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    reset(deg,0);
    int u,v;
    FOR(i,1,n*2){
        scanf("%d%d",&u,&v);
        deg[u]++; deg[v]++;
        if(deg[u]>4 || deg[v]>4){
            puts("-1");
            return 0;
        }
        a[u].pb(v);
        a[v].pb(u);
    }
    arr[1]=1;
    bool ok=0;
    REP(i,sz(a[1])){
        REP(j,sz(a[1])) if(i!=j){
            arr[2]=a[1][i];
            arr[3]=a[1][j];
            u=arr[3];
            REP(z,sz(a[u])){
                v=a[u][z];
                if(v!=arr[1] && v!=arr[2]){
                    arr[4]=v;
                    if(check()){
                        ok=1;
                        FOR(i,1,n) res[i]=arr[i];
                        break;
                    }
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    if(!ok){
        puts("-1");
    }else{
        FOR(i,1,n) printf("%d ",res[i]);
        puts("");
    }
    //getch();
    return 0;
}

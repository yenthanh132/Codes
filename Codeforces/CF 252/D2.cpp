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

const int maxn=3333;
int n,m,a[maxn],com[maxn],cnt,id,prev[maxn];
vector<pii> res;
void dfs(int u){
    ++cnt;
    com[u]=id;
    if(!com[a[u]]) dfs(a[u]);
}

int cal(){
    int res=0;
    reset(com,0);
    id=0;
    FOR(i,1,n) prev[a[i]]=i;
    FOR(i,1,n) if(!com[i]){
        cnt=0;
        ++id;
        dfs(i);
        res+=cnt-1;
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>m;
    int v;
    while((v=cal())!=m){
        if(v<m){
            FOR(i,2,n) if(com[i]!=com[1]){
                res.pb(pii(1,i));
                swap(a[1],a[i]);
                break;
            }
        }else{
            int u=-1;
            FOR(i,1,n) if(a[i]!=i){
                u=i;
                break;
            }
            FOR(i,u+1,n) if(com[i]==com[u]){
                res.pb(pii(u,i));
                swap(a[u],a[i]);
                break;
            }
        }
    }
    printf("%d\n",sz(res));
    REP(i,sz(res)) printf("%d %d ",res[i].fi,res[i].se);
}


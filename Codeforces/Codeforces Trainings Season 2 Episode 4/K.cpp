#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;
const int base=73471;

char s[107];
map<ll,int> mid;
int n,deg[maxn],myq[maxn];
bool mark[maxn];
vector<int> e[maxn];

ll hash(char *s){
    int len=strlen(s);
    ll val=0;
    for(int i=0; i<len; ++i) val=val*base+s[i];
    return val;
}

int getid(ll v){
    if(mid[v]==0){
        mid[v]=++n;
        deg[n]=0;
        return n;
    }
    return mid[v];
}

int main(){
    //freopen("input.txt","r",stdin);
    n=0;
    while(scanf("%s",s)!=EOF){
        ll x=hash(s);
        int u=getid(x);
        mark[u]=1;
        while(1){
            scanf("%s",s);
            if(s[0]=='0' && strlen(s)==1) break;
            x=hash(s);
            int v=getid(x);
            e[v].pb(u);
            ++deg[u];
        }
    }

    int first=1, last=0;
    for(int u=1; u<=n; ++u) if(deg[u]==0 && mark[u]) myq[++last]=u;
    int res = 0;
    while(first<=last){
        int u=myq[first++];
        res++;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            --deg[v];
            if(deg[v]==0) myq[++last]=v;
        }
    }

    cout<<res<<endl;
}

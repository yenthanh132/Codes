#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int lab[maxn],n,mark[maxn];
int x[maxn],y[maxn],m;

int getroot(int u){
    if(lab[u]<0) return u;
    return (lab[u] = getroot(lab[u]));
}

void dsu(int r1, int r2){
    if(lab[r1]>lab[r2]) swap(r1,r2);
    lab[r1] += lab[r2];
    lab[r2] = r1;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) lab[i]=-1;
    for(int i=0, u,v; i<m; ++i){
        scanf("%d%d",&u,&v);
        x[i] = u; y[i] = v;
    }

    reset(mark,0);
    for(int i=m-1; i>=0; --i){
        int r1 = getroot(x[i]), r2 = getroot(y[i]);
        if(r1!=r2){
            dsu(r1,r2);
            mark[i]=1;
        }
    }
    vector<int> ans;
    for(int i=0; i<m; ++i) if(!mark[i]) ans.pb(i+1);
    printf("%d\n",sz(ans));
    for(int i=0; i<sz(ans); ++i) printf("%d\n",ans[i]);
}
